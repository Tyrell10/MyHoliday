;; Auto-generated. Do not edit!


(when (boundp 'Tyrell::demo_srv)
  (if (not (find-package "TYRELL"))
    (make-package "TYRELL"))
  (shadow 'demo_srv (find-package "TYRELL")))
(unless (find-package "TYRELL::DEMO_SRV")
  (make-package "TYRELL::DEMO_SRV"))
(unless (find-package "TYRELL::DEMO_SRVREQUEST")
  (make-package "TYRELL::DEMO_SRVREQUEST"))
(unless (find-package "TYRELL::DEMO_SRVRESPONSE")
  (make-package "TYRELL::DEMO_SRVRESPONSE"))

(in-package "ROS")





(defclass Tyrell::demo_srvRequest
  :super ros::object
  :slots (_in ))

(defmethod Tyrell::demo_srvRequest
  (:init
   (&key
    ((:in __in) "")
    )
   (send-super :init)
   (setq _in (string __in))
   self)
  (:in
   (&optional __in)
   (if __in (setq _in __in)) _in)
  (:serialization-length
   ()
   (+
    ;; string _in
    4 (length _in)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _in
       (write-long (length _in) s) (princ _in s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _in
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _in (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass Tyrell::demo_srvResponse
  :super ros::object
  :slots (_out ))

(defmethod Tyrell::demo_srvResponse
  (:init
   (&key
    ((:out __out) "")
    )
   (send-super :init)
   (setq _out (string __out))
   self)
  (:out
   (&optional __out)
   (if __out (setq _out __out)) _out)
  (:serialization-length
   ()
   (+
    ;; string _out
    4 (length _out)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _out
       (write-long (length _out) s) (princ _out s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _out
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _out (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass Tyrell::demo_srv
  :super ros::object
  :slots ())

(setf (get Tyrell::demo_srv :md5sum-) "e21fb7853ad73d6d988d6371d4fed1e2")
(setf (get Tyrell::demo_srv :datatype-) "Tyrell/demo_srv")
(setf (get Tyrell::demo_srv :request) Tyrell::demo_srvRequest)
(setf (get Tyrell::demo_srv :response) Tyrell::demo_srvResponse)

(defmethod Tyrell::demo_srvRequest
  (:response () (instance Tyrell::demo_srvResponse :init)))

(setf (get Tyrell::demo_srvRequest :md5sum-) "e21fb7853ad73d6d988d6371d4fed1e2")
(setf (get Tyrell::demo_srvRequest :datatype-) "Tyrell/demo_srvRequest")
(setf (get Tyrell::demo_srvRequest :definition-)
      "string in
---
string out

")

(setf (get Tyrell::demo_srvResponse :md5sum-) "e21fb7853ad73d6d988d6371d4fed1e2")
(setf (get Tyrell::demo_srvResponse :datatype-) "Tyrell/demo_srvResponse")
(setf (get Tyrell::demo_srvResponse :definition-)
      "string in
---
string out

")



(provide :Tyrell/demo_srv "e21fb7853ad73d6d988d6371d4fed1e2")


