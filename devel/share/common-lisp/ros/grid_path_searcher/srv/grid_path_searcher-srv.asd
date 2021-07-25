
(cl:in-package :asdf)

(defsystem "grid_path_searcher-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "get_plan" :depends-on ("_package_get_plan"))
    (:file "_package_get_plan" :depends-on ("_package"))
    (:file "update_goal" :depends-on ("_package_update_goal"))
    (:file "_package_update_goal" :depends-on ("_package"))
  ))