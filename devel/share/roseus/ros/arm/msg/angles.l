;; Auto-generated. Do not edit!


(when (boundp 'arm::angles)
  (if (not (find-package "ARM"))
    (make-package "ARM"))
  (shadow 'angles (find-package "ARM")))
(unless (find-package "ARM::ANGLES")
  (make-package "ARM::ANGLES"))

(in-package "ROS")
;;//! \htmlinclude angles.msg.html


(defclass arm::angles
  :super ros::object
  :slots (_shoulder _elbow _wrist ))

(defmethod arm::angles
  (:init
   (&key
    ((:shoulder __shoulder) 0)
    ((:elbow __elbow) 0)
    ((:wrist __wrist) 0)
    )
   (send-super :init)
   (setq _shoulder (round __shoulder))
   (setq _elbow (round __elbow))
   (setq _wrist (round __wrist))
   self)
  (:shoulder
   (&optional __shoulder)
   (if __shoulder (setq _shoulder __shoulder)) _shoulder)
  (:elbow
   (&optional __elbow)
   (if __elbow (setq _elbow __elbow)) _elbow)
  (:wrist
   (&optional __wrist)
   (if __wrist (setq _wrist __wrist)) _wrist)
  (:serialization-length
   ()
   (+
    ;; uint16 _shoulder
    2
    ;; uint16 _elbow
    2
    ;; uint16 _wrist
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _shoulder
       (write-word _shoulder s)
     ;; uint16 _elbow
       (write-word _elbow s)
     ;; uint16 _wrist
       (write-word _wrist s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _shoulder
     (setq _shoulder (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _elbow
     (setq _elbow (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _wrist
     (setq _wrist (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get arm::angles :md5sum-) "8960ce5da37f48308cf296b103d3ad7f")
(setf (get arm::angles :datatype-) "arm/angles")
(setf (get arm::angles :definition-)
      "uint16 shoulder
uint16 elbow
uint16 wrist

")



(provide :arm/angles "8960ce5da37f48308cf296b103d3ad7f")


