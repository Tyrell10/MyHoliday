;; Auto-generated. Do not edit!


(when (boundp 'Tyrell::demo_msg)
  (if (not (find-package "TYRELL"))
    (make-package "TYRELL"))
  (shadow 'demo_msg (find-package "TYRELL")))
(unless (find-package "TYRELL::DEMO_MSG")
  (make-package "TYRELL::DEMO_MSG"))

(in-package "ROS")
;;//! \htmlinclude demo_msg.msg.html


(defclass Tyrell::demo_msg
  :super ros::object
  :slots (_greeting _number ))

(defmethod Tyrell::demo_msg
  (:init
   (&key
    ((:greeting __greeting) "")
    ((:number __number) 0)
    )
   (send-super :init)
   (setq _greeting (string __greeting))
   (setq _number (round __number))
   self)
  (:greeting
   (&optional __greeting)
   (if __greeting (setq _greeting __greeting)) _greeting)
  (:number
   (&optional __number)
   (if __number (setq _number __number)) _number)
  (:serialization-length
   ()
   (+
    ;; string _greeting
    4 (length _greeting)
    ;; int32 _number
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _greeting
       (write-long (length _greeting) s) (princ _greeting s)
     ;; int32 _number
       (write-long _number s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _greeting
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _greeting (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; int32 _number
     (setq _number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get Tyrell::demo_msg :md5sum-) "4d44a7bb82ba135859a5038705fd5c1d")
(setf (get Tyrell::demo_msg :datatype-) "Tyrell/demo_msg")
(setf (get Tyrell::demo_msg :definition-)
      "string greeting
int32 number

")



(provide :Tyrell/demo_msg "4d44a7bb82ba135859a5038705fd5c1d")


