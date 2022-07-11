open Thread

let id1 = Thread.create_thread "Hello there! This is the first thread!";;
let () = sleep 3;;
let id2 = Thread.create_thread "This is the second thread!";;
let id3 = create_thread "This is the third thread!";;

let () = join_thread id1;;
let () = join_thread id2;;
let () = join_thread id3;;

let t_id3 = self_thread;;
