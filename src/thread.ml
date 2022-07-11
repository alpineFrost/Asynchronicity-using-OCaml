external create_thread: string -> int64 = "caml_create_thread"

external join_thread: int64 -> unit = "caml_join_thread"

external self_thread: unit -> int64 = "caml_self_thread"

external sleep: int -> unit = "caml_sleep"
