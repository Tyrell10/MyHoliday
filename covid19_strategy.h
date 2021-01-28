#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <fukuro_common/WorldModel.h>
#include <fukuro_common/KeypadService.h>
#include <fukuro_common/RobotControl.h>
#include <fukuro_common/RobotControlInfo.h>
#include <fukuro_common/StrategyInfo.h>
#include <fukuro_common/StrategyService.h>
#include <fukuro_common/Shoot.h>
#include <fukuro_common/StrategyPositioning.h>
#include <fukuro_common/Teammates.h>
#include <fukuro_common/InterceptPoint.h>
#include <fukuro_common/RobotUtility.h>

#ifndef FIRST_BUILD
//#include <fukuro_strategy/FukuroStrategyConfig.h>
#endif

#include <chrono>
#include <mutex>
#include <thread>
#include <vector>
#include <random>
#include <tuple>
#include <queue>
#include <cmath>
#include <string>

#include "fukuro/core/field.hpp"

namespace fukuro {

enum GameState {POSITIONING,HALT};

enum Role {DEFENDER,STRIKER};

enum State {TIMER, KICKOFF, PASSING, IDLE, HOMING,
            BALL_SEARCHING, DRIBBLE_BALL, KICK_BALL, APPROACH_BALL};

enum PlayArea {OPP_LEFT,OPP_RIGHT};

typedef std::tuple<double,double,int> Position;
typedef std::priority_queue<Position,std::vector<Position>,std::greater<Position>> Neighbor;

struct RobotInfo{

    int robot_name;

    double x;
    double y;
    double theta;

    double kick_x;
    double kick_y;
    double kick_angle;

    double ball_shield_angle;

    double error_angle;
    double error_radius;

    double home_x;
    double home_y;
    double home_theta;

    double intercept_x;
    double intercept_y;
    double intercept_theta;
    bool isInterceptValid;

    bool isNearestoBall;
    bool isBallEngaged;

    PlayArea playarea;
    PlayArea checkPlayArea(double x, double y);

    GameState gstate;
    Role role;
    State state,last_state;

    Neighbor neighbor, neighbor_ball;
    double neighbor_x;
    double neighbor_y;
    double neighbor_angle;

};

struct BallInfo{

    double local_x;
    double local_y;
    double global_x;
    double global_y;
    double local_x_last_seen;
    double local_y_last_seen;

    bool isVisible;
    ros::Time last_seen;

};

class StrategyCOVID19{
public:
    typedef std::chrono::high_resolution_clock Clock;
    typedef std::chrono::duration<double,std::milli> Duration;
    StrategyCOVID19(ros::NodeHandle& nh);
    ~StrategyCOVID19();

    void process();
    Role roleChecking(std::string str);
    std::string getRole(Role role);
    State checkState(std::string str);
    std::string getState(State state);
    void setStraightLine(double x1, double x2, double y1, double y2);
    double getYStraightLine(double X);

    void updateTeammatesInfo(const fukuro_common::Teammates::ConstPtr& teammates);
    void updateWorldModelInfo(const fukuro_common::WorldModel::ConstPtr& wm);
    void updateStrategyPositioningInfo(const fukuro_common::StrategyPositioning::ConstPtr& strpos);
    void updateRobotControlInfo(const fukuro_common::RobotControlInfo::ConstPtr& robotinfo);
    void updateRobotUtility(const fukuro_common::RobotUtility::ConstPtr& status);
#ifndef FIRST_BUILD
    //void reconfigure(const fukuro_strategy::FukuroStrategyConfig& config, uint32_t level);
#endif
    bool StrategyRequestHandler(fukuro_common::StrategyService::Request &request, fukuro_common::StrategyService::Response &response);

private:
    inline void back2home();
    inline void passing_ball();
    inline void timer();
    inline void dribble_ball();
    inline void stop();
    inline void kick_ball();
    inline void approach_ball();
    inline void kick_off();
    inline void go_to_pos(double x, double y, double theta, std::string local = "", bool dribbler = false, bool planning = true);

    fukuro::RobotInfo robot;
    fukuro::BallInfo ball;
    ros::NodeHandle& node;
    ros::Publisher robotcontrol_pub;
    ros::Publisher strinfo_pub;
    fukuro_common::Shoot kicker_service;
    std::string robot_name;
    fukuro_common::RobotControl rcontrolmsg;
    ros::Time last_time;

    bool kicker_failed;
    bool change_kick_pos = false;
    bool isTravelling = false;
    bool isKickOff = true;

    double x1;
    double x2;
    double y1;
    double y2;

};

}
