external sem_create: unit -> int = "caml_sem_create_thread"

external sem_wait: int -> int = "caml_sem_wait"

external sem_post: int -> int = "caml_sem_post"
