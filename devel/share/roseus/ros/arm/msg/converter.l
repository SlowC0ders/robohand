;; Auto-generated. Do not edit!


(when (boundp 'arm::converter)
  (if (not (find-package "ARM"))
    (make-package "ARM"))
  (shadow 'converter (find-package "ARM")))
(unless (find-package "ARM::CONVERTER")
  (make-package "ARM::CONVERTER"))

(in-package "ROS")
;;//! \htmlinclude converter.msg.html


(defclass arm::converter
  :super ros::object
  :slots (_object ))

(defmethod arm::converter
  (:init
   (&key
    ((:object __object) (instance arm::coord :init))
    )
   (send-super :init)
   (setq _object __object)
   self)
  (:object
   (&rest __object)
   (if (keywordp (car __object))
       (send* _object __object)
     (progn
       (if __object (setq _object (car __object)))
       _object)))
  (:serialization-length
   ()
   (+
    ;; arm/coord _object
    (send _object :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; arm/coord _object
       (send _object :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; arm/coord _object
     (send _object :deserialize buf ptr-) (incf ptr- (send _object :serialization-length))
   ;;
   self)
  )

(setf (get arm::converter :md5sum-) "1431af4482a444b26905122d6a7f3716")
(setf (get arm::converter :datatype-) "arm/converter")
(setf (get arm::converter :definition-)
      "coord object

================================================================================
MSG: arm/coord
int32 x
int32 y

")



(provide :arm/converter "1431af4482a444b26905122d6a7f3716")


