{"pthread_atfork", pthread_atfork},
{"pthread_create", my_pthread_create},
{"pthread_kill", pthread_kill},
{"pthread_exit", pthread_exit},
{"pthread_join", pthread_join},
{"pthread_detach", pthread_detach},
{"pthread_self", pthread_self},
{"pthread_equal", pthread_equal},
{"pthread_getschedparam", pthread_getschedparam},
{"pthread_setschedparam", pthread_setschedparam},
{"pthread_mutex_init", my_pthread_mutex_init},
{"pthread_mutex_destroy", my_pthread_mutex_destroy},
{"pthread_mutex_lock", my_pthread_mutex_lock},
{"pthread_mutex_unlock", my_pthread_mutex_unlock},
{"pthread_mutex_trylock", my_pthread_mutex_trylock},
{"pthread_mutex_lock_timeout_np", my_pthread_mutex_lock_timeout_np},
{"pthread_mutexattr_init", pthread_mutexattr_init},
{"pthread_mutexattr_destroy", pthread_mutexattr_destroy},
{"pthread_mutexattr_gettype", pthread_mutexattr_gettype},
{"pthread_mutexattr_settype", pthread_mutexattr_settype},
{"pthread_mutexattr_getpshared", pthread_mutexattr_getpshared},
{"pthread_mutexattr_setpshared", my_pthread_mutexattr_setpshared},
{"pthread_condattr_init", pthread_condattr_init},
{"pthread_condattr_getpshared", pthread_condattr_getpshared},
{"pthread_condattr_setpshared", pthread_condattr_setpshared},
{"pthread_condattr_destroy", pthread_condattr_destroy},
{"pthread_cond_init", my_pthread_cond_init},
{"pthread_cond_destroy", my_pthread_cond_destroy},
{"pthread_cond_broadcast", my_pthread_cond_broadcast},
{"pthread_cond_signal", my_pthread_cond_signal},
{"pthread_cond_wait", my_pthread_cond_wait},
{"pthread_cond_timedwait", my_pthread_cond_timedwait},
{"pthread_cond_timedwait_monotonic", my_pthread_cond_timedwait},
{"pthread_cond_timedwait_monotonic_np", my_pthread_cond_timedwait},
{"pthread_cond_timedwait_relative_np", my_pthread_cond_timedwait_relative_np},
{"pthread_key_delete", pthread_key_delete},
{"pthread_setname_np", my_pthread_setname_np},
{"pthread_once", pthread_once},
{"pthread_key_create", pthread_key_create},
{"pthread_setspecific", pthread_setspecific},
{"pthread_getspecific", pthread_getspecific},
{"pthread_attr_init", my_pthread_attr_init},
{"pthread_attr_destroy", my_pthread_attr_destroy},
{"pthread_attr_setdetachstate", my_pthread_attr_setdetachstate},
{"pthread_attr_getdetachstate", my_pthread_attr_getdetachstate},
{"pthread_attr_setschedpolicy", my_pthread_attr_setschedpolicy},
{"pthread_attr_getschedpolicy", my_pthread_attr_getschedpolicy},
{"pthread_attr_setschedparam", my_pthread_attr_setschedparam},
{"pthread_attr_getschedparam", my_pthread_attr_getschedparam},
{"pthread_attr_setstacksize", my_pthread_attr_setstacksize},
{"pthread_attr_getstacksize", my_pthread_attr_getstacksize},
{"pthread_attr_setstackaddr", my_pthread_attr_setstackaddr},
{"pthread_attr_getstackaddr", my_pthread_attr_getstackaddr},
{"pthread_attr_setstack", my_pthread_attr_setstack},
{"pthread_attr_getstack", my_pthread_attr_getstack},
{"pthread_attr_setguardsize", my_pthread_attr_setguardsize},
{"pthread_attr_getguardsize", my_pthread_attr_getguardsize},
{"pthread_attr_setscope", my_pthread_attr_setscope},
{"pthread_attr_getscope", my_pthread_attr_getscope},
{"pthread_getattr_np", my_pthread_getattr_np},
{"pthread_rwlockattr_init", my_pthread_rwlockattr_init},
{"pthread_rwlockattr_destroy", my_pthread_rwlockattr_destroy},
{"pthread_rwlockattr_setpshared", my_pthread_rwlockattr_setpshared},
{"pthread_rwlockattr_getpshared", my_pthread_rwlockattr_getpshared},
{"pthread_rwlock_init", my_pthread_rwlock_init},
{"pthread_rwlock_destroy", my_pthread_rwlock_destroy},
{"pthread_rwlock_unlock", my_pthread_rwlock_unlock},
{"pthread_rwlock_wrlock", my_pthread_rwlock_wrlock},
{"pthread_rwlock_rdlock", my_pthread_rwlock_rdlock},
{"pthread_rwlock_tryrdlock", my_pthread_rwlock_tryrdlock},
{"pthread_rwlock_trywrlock", my_pthread_rwlock_trywrlock},
{"pthread_rwlock_timedrdlock", my_pthread_rwlock_timedrdlock},
{"pthread_rwlock_timedwrlock", my_pthread_rwlock_timedwrlock},
