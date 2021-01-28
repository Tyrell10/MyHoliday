/*
 *                                               بسم الله الرحمن الرحيم
*/

#include "covid19_strategy.h"

#define BORDER_FIELD_STOP

using namespace fukuro;

StrategyCOVID19::StrategyCOVID19(ros::NodeHandle &nh):
  node(nh), x1(0.0), x2(0.0), y1(0.0), y2(0.0), kicker_failed(false)

{
  std::string state;
  if(ros::param::get("/strategy_state",state)){
      robot.state = checkState(state);
  }

  if(!ros::get_environment_variable(robot_name,"FUKURO"))
  {
      ROS_ERROR("robot name empty!!! export FUKURO=fukuro1");
      exit(-1);
  }

  robotcontrol_pub = node.advertise<fukuro_common::RobotControl>(robot_name+std::string("/robot_control"),1);
  strinfo_pub = node.advertise<fukuro_common::StrategyInfo>(robot_name+std::string("/strategy_info"),1);

  std::string role;
  if(ros::param::get("/robot_role",role)){
      robot.role = roleChecking(role);
  }

  switch(robot.role){
  case DEFENDER:{
    robot.home_x = COVID19_HOME_RIGHT_X;
    robot.home_y = COVID19_HOME_RIGHT_Y;
    robot.home_theta = -M_PI_2;
    break;
  }
  case STRIKER:{
    robot.home_x = COVID19_HOME_LEFT_X;
    robot.home_y = COVID19_HOME_LEFT_Y;
    robot.home_theta = M_PI_2;
    break;
    }
  }

  robot.kick_x = DEFAULT_KICK_TARGET_X;
  robot.kick_y = DEFAULT_KICK_TARGET_Y;
  robot.kick_angle = 0.0;
  robot.ball_shield_angle = 0.0;

  robot.error_angle = 0.0;
  robot.error_radius = 0.0;

  ball.global_x = 0.0;
  ball.global_y = 0.0;
  ball.local_x = 0.0;
  ball.local_y = 0.0;

  robot.neighbor_x = 0.0;
  robot.neighbor_y = 0.0;

  ball.isVisible = false;
  robot.isBallEngaged = false;

}

StrategyCOVID19::~StrategyCOVID19(){

}

void StrategyCOVID19::process(){

  fukuro_common::StrategyInfo strinfo;
  strinfo.strategy_state = getState(robot.state);
  strinfo.role = getRole(robot.role);

  //std::cout << strinfo.role << std::endl;

  try{

      strinfo_pub.publish(strinfo);
      robotcontrol_pub.publish(rcontrolmsg);

      switch (robot.state) {
      case TIMER:{
          robot.playarea = robot.checkPlayArea(robot.x,robot.y);
          timer();
          robot.last_state = TIMER;
          ROS_INFO("[STRATEGY] TIMER");
          break;
      }
      case IDLE:{
          robot.playarea = robot.checkPlayArea(robot.x,robot.y);
          stop();
          robot.last_state = IDLE;
          ROS_INFO("[STRATEGY] STOP");
          break;
      }
      case HOMING:{
          back2home();
          robot.last_state = HOMING;
          ROS_INFO("[STRATEGY] POSITIONING");
          break;
      }
      case PASSING:{
          passing_ball();
          robot.last_state = PASSING;
          ROS_INFO("[STRATEGY] PASSING BALL");
          break;
      }
      case BALL_SEARCHING:{
          ball_search();
          robot.last_state = BALL_SEARCHING;
          ROS_INFO("[STRATEGY] BALL SEARCHING");
          break;
      }
      case APPROACH_BALL:{
          approach_ball();
          robot.last_state = APPROACH_BALL;
          ROS_INFO("[STRATEGY] APPROACH BALL");
          break;
      }
      case DRIBBLE_BALL:{
          dribble_ball();
          robot.last_state = DRIBBLE_BALL;
          ROS_INFO("[STRATEGY] DRIBBLE BALL");
          break;
      }
      case KICK_BALL:{
          kick_ball();
          robot.last_state = KICK_BALL;
          ROS_INFO("[STRATEGY] KICK BALL");
          break;
      }
      default:{
          robot.playarea = robot.checkPlayArea(robot.x,robot.y);
          timer();
          robot.last_state = TIMER;
          ROS_INFO("[STRATEGY] TIMER");
          break;
      }
      };

  }

  catch(std::exception& e){
      return;
  }

}

Role StrategyCOVID19::roleChecking(std::string str){

  Role ret;

  //std::cout << "role checking " << str << std::endl;

  if(str.find("def")!=std::string::npos){
      ret = DEFENDER;
      kicker_failed = (str.find("2")!=std::string::npos)? true : false;
  }
  else if(str.find("str")!=std::string::npos){
      ret = STRIKER;
      kicker_failed = (str.find("2")!=std::string::npos)? true : false;
  }

  return ret;

}

std::string StrategyCOVID19::getRole(Role role){

  std::string ret;

  switch(role){
  case DEFENDER:{
      ret = "defender";
      break;
  }
  case STRIKER:{
      ret = "striker";
      break;
  }
  };

  return ret;

}

PlayArea RobotInfo::checkPlayArea(double x, double y){

  PlayArea ret;

  if((x>0) && (y>0)){
      ret = OPP_RIGHT;
  }
  else if((x>0) && (y<=0)){
      ret = OPP_LEFT;
  }

  return ret;

}

State StrategyCOVID19::checkState(std::string str){

  State ret;

  if(str.find("timer")!=std::string::npos){
      ret = TIMER;
  }
  else if(str.find("stop")!=std::string::npos){
      ret = IDLE;
  }
  else{
      ret = robot.state;
  }

  return ret;

}

std::string StrategyCOVID19::getState(State state){

  std::string ret;

  switch(state){
  case TIMER:{
      ret = "timer";
      break;
  }
  case IDLE:{
      ret = "stop";
      break;
  }
  case HOMING:{
      ret = "back2home";
      break;
  }
  case BALL_SEARCHING:{
      ret = "ball-searching";
      break;
  }
  case APPROACH_BALL:{
      ret = "approach-ball";
      break;
  }
  case PASSING:{
      ret = "passing-ball";
      break;
  }
  case DRIBBLE_BALL:{
      ret = "dribble-ball";
      break;
  }
  case KICK_BALL:{
      ret = "kick-ball";
      break;
  }
  }

  return ret;


}

void StrategyCOVID19::setStraightLine(double x1, double x2, double y1, double y2){

}

double StrategyCOVID19::getYStraightLine(double X){

}

void StrategyCOVID19::updateTeammatesInfo(const fukuro_common::Teammates::ConstPtr& teammates){

  try{
      robot.robot_name = teammates->robotname;

      switch(teammates->behavior){
      case 0:{
          robot.gstate = POSITIONING;
          break;
      }
      case 2:
      {
          robot.gstate = HALT;
          break;
      }
      }

      while(!robot.neighbor_ball.empty()) robot.neighbor_ball.pop();
      while(!robot.neighbor.empty()) robot.neighbor.pop();

      if(teammates->pose.size()>0){

          //std::cout << "[TEAMMATE SIZE] " << teammates->pose.size() << std::endl;

          for(int i=0; i<teammates->pose.size();i++){
              if(teammates->available[i]){
                  if(i!=robot.robot_name){
                      auto dist = std::hypot((ball.global_x-teammates->pose[i].x),(ball.global_y-teammates->pose[i].y));
                      auto angle = std::atan2((ball.global_y-teammates->pose[i].y),(ball.global_x-teammates->pose[i].x));
                      robot.neighbor_ball.push(std::make_tuple(dist,angle,i));

                      dist = std::hypot((teammates->pose[i].x-robot.x),(teammates->pose[i].y-robot.y));
                      angle = std::atan2((teammates->pose[i].y-robot.y),(teammates->pose[i].x-robot.x));
                      robot.neighbor_angle = angle;
                      robot.neighbor.push(std::make_tuple(dist,angle,i));
                  }
                  else{
                      auto dist = std::hypot((ball.local_x),(ball.local_y));
                      auto angle = std::atan2((ball.local_y),(ball.local_x));
                      robot.neighbor_ball.push(std::make_tuple(dist,angle,i));
                  }
              }
          }

          if(!robot.neighbor.empty()){
              auto top = robot.neighbor_ball.top();

              //std::cout << "ERROR PASSED!!!" << std::endl;

              robot.isNearestoBall = std::get<2>(top) == robot.robot_name? true:false;
              top = robot.neighbor.top();
              auto idx = std::get<2>(top);
              robot.neighbor_x = teammates->pose[idx].x;
              robot.neighbor_y = teammates->pose[idx].y;
          }
          else{
              robot.isNearestoBall = true;
              robot.neighbor_x = GOAL_POS_X;
              robot.neighbor_y = GOAL_POS_Y;
          }
      }
      else{
          robot.isNearestoBall = true;
      }

  }
  catch(std::exception& e){
      return;
  }

}

void StrategyCOVID19::updateWorldModelInfo(const fukuro_common::WorldModel::ConstPtr& wm){

  try{
      robot.x = wm->pose.x;
      robot.y = wm->pose.y;
      robot.theta = wm->pose.theta;

      ball.local_x = wm->local_balls_kf.x;
      ball.local_y = wm->local_balls_kf.y;
      ball.global_x = wm->global_balls_kf.x;
      ball.global_x = wm->global_balls_kf.x;

      ball.isVisible = wm->ball_visible? true : false;
      ball.isVisible = ((ball.local_x==0.0)&&(ball.local_y==0.0))? false : true;

      auto now = ros::Time::now();
      if(ball.isVisible){
        ball.isVisible = true;
        ball.last_seen = now;
        ball.local_x_last_seen = wm->local_balls_kf.x;
        ball.local_y_last_seen = wm->local_balls_kf.y;
      }
      else if( (now - ball.last_seen) > ros::Duration(1) ){
        ball.isVisible = false;
      }
  }
  catch(std::exception& e){
      return;
  }

}

void StrategyCOVID19::updateStrategyPositioningInfo(const fukuro_common::StrategyPositioning::ConstPtr& strpos){

  try{
      robot.kick_x = KICK_TARGET_1_X;
      robot.kick_y = KICK_TARGET_1_Y;
      robot.kick_angle = std::atan2((GOAL_POS_Y-KICK_TARGET_1_Y),(GOAL_POS_X-KICK_TARGET_1_X));

      if(kicker_failed){
          robot.kick_x = GOAL_POS_X;
          robot.kick_y = GOAL_POS_Y;
          robot.kick_angle = 0.0;
      }
  }

}

void StrategyCOVID19::updateRobotControlInfo(const fukuro_common::RobotControlInfo::ConstPtr& robotinfo){

  try{
      robot.error_radius = robotinfo->error_radius;
      robot.error_angle = robotinfo->error_angle;
  }
  catch(std::exception& e){
      return;
  }

}

void StrategyCOVID19::updateRobotUtility(const fukuro_common::RobotUtility::ConstPtr& status){

  robot.isBallEngaged = status->ball_engage;

}

bool StrategyCOVID19::StrategyRequestHandler(fukuro_common::StrategyService::Request &request, fukuro_common::StrategyService::Response &response){

  std::string reqrole(request.role);
  if(reqrole!="")
      robot.role = roleChecking(reqrole);

  std::string strequest(request.strategy_state);
  if(strequest!="")
      robot.state = checkState(strequest);

  response.ok = 1;

}

void StrategyCOVID19::go_to_pos(double x, double y, double theta, std::string local = "", bool dribbler = false, bool planning = true){

#ifdef BORDER_FIELD_STOP
    double max_pos_width = (FIELD_WIDTH+15.0)/200.0;
    double max_pos_height = (FIELD_HEIGHT+15.0)/200.0;
    double max_neg_height = -max_pos_height;

    if(ball.isVisible){

      if(ball.global_x<=0.0 || ball.global_x>=max_pos_width ||
          ball.global_y<=max_neg_height|| ball.global_y>=max_pos_height){
          x = 0.0;
          y = 0.0;
          local = "local";
          dribbler = false;
      }

    }
    else
      ball.isVisible = false;
#endif

    rcontrolmsg.target_pose.x = x;
    rcontrolmsg.target_pose.y = y;
    rcontrolmsg.target_pose.theta = theta;
    rcontrolmsg.plan = planning;
    rcontrolmsg.option.data = local=="local"?"local":"";
    rcontrolmsg.dribbler = dribbler?1:0;

}

void StrategyCOVID19::stop(){

  go_to_pos(0.0,0.0,0.0,"local",false,false);

}

void StrategyCOVID19::timer(){

  static int count_engaged = 0;
  static bool firstTouch = true;
  auto radius = std::hypot(ball.local_x,ball.local_x);

  switch(robot.gstate){
  case POSITIONING:
  {
      switch(robot.role){
      case STRIKER:{
        auto angle = std::atan2(1.5,0.0);

        if(isKickOff && !robot.isBallEngaged)
          go_to_pos(0.0,1.5,angle,"",false,true);

        if(!robot.isBallEngaged)
        {
          firstTouch = false;

          if(ball.isVisible && isKickOff){
              robot.state = APPROACH_BALL;
              return;
          }
          else if(radius < 1.0){
              robot.state = APPROACH_BALL;
              return;
          }
        }

        if(count_engaged < 1 && !firstTouch){
           ++count_engaged;
           firstTouch = true;
           robot.state = PASSING;
           return;
        }
        else if(!firstTouch){
           angle = M_PI;
           auto ball_shield_angle = std::atan2(ball.local_y,ball.local_x);
           auto error_radius_pos = std::hypotf(std::fabs(1.25-robot.x), std::fabs(0.0-robot.y));
           bool isDribble = false;

           go_to_pos(1.25,0.0,angle,"",false,false);

           isDribble = (radius < RADIUS_BALL_DRIBBLE)? true:false;

           if(robot.isBallEngaged){
              count_engaged = 0;
              angle = 0.0;
              auto error_angle = std::fabs(angle-robot.theta);

              go_to_pos(0.0,0.0,angle,"local",true,false);

              if(error_angle < ERROR_ANGLE){
                stop();
                robot.state = KICK_BALL;
                return;
              }
           }
           else if(error_radius_pos < ERROR_RADIUS)
              go_to_pos(0.0, 0.0, ball_shield_angle, "local", isDribble, false);
        }

        break;
      }
      case DEFENDER:{
        auto angle = std::atan2(-1.5,0.0);
        auto error_radius = std::hypot(std::fabs(0.0-robot.x), std::fabs(-1.5-robot.y));
        bool isDribble = false;

        isDribble = (radius < RADIUS_BALL_DRIBBLE)? true:false;

        if(isKickOff && !robot.isBallEngaged){
          go_to_pos(0.0,-1.5,angle,"",false,true);

          if(error_radius < ERROR_RADIUS)
              go_to_pos(0.0,0.0,robot.home_theta,isDribble,false);
        }

        if(!robot.isBallEngaged){
          robot.state = APPROACH_BALL;
          return;
        }
        else{
          robot.state = PASSING;
          return;
        }
      }
      }

      break;
  }
  case HALT:{
    robot.state = HOMING;
    isKickOff = true;
    std::cout << "[STRATEGY] " << "GAME RESTARTED" << std::endl;
    return;
  }
  }

}

void StrategyCOVID19::passing_ball(){

  switch(robot.role){
  case STRIKER:{
    auto angle = std::atan2((robot.neighbor_y-robot.y), (robot.neighbor_x-robot.x));
    auto error_angle = std::fabs(angle-robot.theta);

    if(isKickOff)
      angle = robot.home_theta;

    go_to_pos(0.0,0.0,angle,"local",true,false);

    if(error_angle < ERROR_ANGLE){
      kick_ball();
    }

    break;
  }
  case DEFENDER:{
    static ros::Time now;
    //now = ros::Time::now();
    //auto radius = std::hypot(std::fabs(robot.neighbor_x-robot.x), std::fabs(robot.neighbor_y-robot.y));
    auto angle = std::atan2((robot.neighbor_y-robot.y), (robot.neighbor_x-robot.x));
    auto error_radius = std::hypot(std::fabs(0.0-robot.x), std::fabs(0.0-robot.y));
    auto error_angle = std::fabs(angle-robot.theta);

    if(isKickOff){
      angle = 0.0;
      go_to_pos(0.0,0.0,angle,"local",true,false);

      if((error_radius < ERROR_RADIUS) && (error_angle < ERROR_ANGLE)){
          kick_ball();
      }
    }

//    if(now < 4.0){
//      go_to_pos(0.0, 0.0, angle, "local", true, false);
//    }
//    else{
//      now = 0.0;
//      go_to_pos(std::fabs(robot.neighbor_x-0.5),std::fabs(robot.neighbor_y-0.5),angle,"",true,true);

//      if(radius < 1.5){
//        if(error_angle < ERROR_ANGLE){
//            kick_ball();
//        }
//      }
//    }

    break;
  }
  }

}

void StrategyCOVID19::kick_ball(){

  int kick_mode;

  if(robot.gstate==HALT){
      stop();
      robot.state=HOMING;
      return;
  }

  kick_mode = (robot.last_state==PASSING)? 1:2;

  kicker_service.request.kick_request = kick_mode;

  if(ros::service::call(robot_name+std::string("/kick_service"),kicker_service)){
      ROS_INFO("KICK SUCCESS!!");
  }
  else{
      ROS_INFO("KICK FAILED!!");
  }

  switch(robot.role){
  case DEFENDER:{
    robot.state = HOMING;
    isKickOff = false;
    return;
  }
  case STRIKER:{
    robot.state = TIMER;
    isKickOff = false;
    return;
  }
  }

}

void StrategyCOVID19::approach_ball(){

  auto radius = std::hypot(ball.local_x,ball.local_y);
  auto angle = std::atan2(ball.local_y,ball.local_x);
  auto error_radius = std::hypot(std::fabs(ball.local_x-robot.x), std::fabs(ball.local_y-robot.y));
  bool isDribble = false;

  if(robot.gstate==HALT) {
      stop();
      robot.state = HOMING;
      return;
  }

  if(robot.isBallEngaged){
      robot.state = TIMER;
      return;
  }

  switch(robot.role){
  case STRIKER:{
    isDribble = (radius < RADIUS_BALL_DRIBBLE)? true:false;

    if(error_radius < ERROR_RADIUS){
        if(isKickOff)
           angle = robot.home_theta;

        go_to_pos(ball.local_x,ball.local_y,angle,"local",true,false);
    }
    else{
        go_to_pos(ball.local_x,ball.local_y,angle,"local",isDribble,false);
    }

    break;
  }
  case DEFENDER:{
    isDribble = (radius < RADIUS_BALL_DRIBBLE)? true:false;

    if(isKickOff && radius < 1.5){
        go_to_pos(0.0, 0.0,angle,"local",isDribble,false);

        if(isDribble)
          go_to_pos(ball.local_x,ball.local_y,angle,"local",true,false);
    }
    else{
        go_to_pos(ball.local_x,ball.local_y,angle,"local",isDribble,false);
    }

    break;
  }
  }

}

void StrategyCOVID19::dribble_ball(){



}

void StrategyCOVID19::back2home(){

  auto error_radius = std::hypotf(std::fabs(robot.home_x-robot.x), std::fabs(robot.home_y-robot.y));
  double error_angle;

  go_to_pos(robot.home_x,robot.home_y,robot.home_theta,"",false,true);

  if(error_radius < ERROR_RADIUS){
    switch(robot.playarea){
    case OPP_LEFT:{
      error_angle = std::fabs(M_PI_2-robot.theta);
    }
    case OPP_RIGHT:{
      error_angle = std::fabs(-M_PI_2-robot.theta);
    }
    }

    go_to_pos(0.0, 0.0,robot.home_theta,"local",false, false);

    if(error_angle < ERROR_ANGLE)
      stop();
  }

}
