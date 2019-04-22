
(cl:in-package :asdf)

(defsystem "Tyrell-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "demo_srv" :depends-on ("_package_demo_srv"))
    (:file "_package_demo_srv" :depends-on ("_package"))
  ))