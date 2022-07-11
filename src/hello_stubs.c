#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <caml/mlvalues.h>
#include <semaphore.h>
#define SUCCESS 0
#define FAILURE 1


void* thread_fn(void* args);

CAMLprim value
caml_create_thread(value msg) {
  char* message = String_val(msg);
  pthread_t thread_id;
  printf("Creating...\n");
  if (pthread_create(&thread_id, NULL, thread_fn, (void *) message) != SUCCESS) {
    perror("Main: Error creating thread. Stopping now...\n");
  }
  return Val_long(thread_id);
}

CAMLprim value
caml_join_thread(value id) {
  pthread_t thread_id = Long_val(id);

  void *thread_result;

  printf("Joining...\n");
  if(pthread_join(thread_id, &thread_result) != SUCCESS) {
    perror("Main: Error joining thread. Stopping now...\n");
  }

  return Val_unit;
}

CAMLprim value
caml_self_thread(value unit) {
  printf("Self ID...\n");
  pthread_t id = pthread_self();
  return Val_long(id);
}

CAMLprim value
caml_exit_thread(value id) {
  pthread_t thread_id = Long_val(id);

  pthread_exit("Exited");
  printf("Exiting...\n");
  printf("Exiting...\n");
  return Val_unit;
}

CAMLprim value
caml_sem_create_thread(){
  int mutex = 0;
  printf("Creating semaphore...\n");
  return Val_int(mutex);
}

CAMLprim value
caml_sem_post(value i){
  int t = Int_val(i);
  t = t+1; //unlock
  printf("%d\n",t );
  return Val_int(t);
}

CAMLprim value
caml_sem_wait(value i){
  int t = Int_val(i);
  if(t > 0){
     t--;//lock
  }
  else {
    printf("Not free..\n");
  }
  printf("%d\n",t );
  return Val_int(t);
}

CAMLprim value
caml_sleep(value i){
  int t = Int_val(i);
  printf("Going to sleep state\n");
  sleep(i);
  return Val_unit;
}
void* thread_fn(void * args) {
  printf("Thread: Thread started running...\n");
  printf("Thread: The message given is: %s\n", (char *) args);
}
