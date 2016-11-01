#include <stdio.h>
#include <lxc/lxccontainer.h>

void salut(void){
  printf("salut\n");
}

int main(int argc, char ** argv) {
  struct lxc_container *c;
  int ret = 1;
  struct lxc_attach_command_t t = {argv[0],argv};

  /* Setup container struct */
  c = lxc_container_new("apicontainer", NULL);
  if (!c) {
    fprintf(stderr, "Failed to setup lxc_container struct\n");
    goto out;
  }


  /* Start the container */
  if (!c->start(c, 0, NULL)) {
    fprintf(stderr, "Failed to start the container\n");
    goto out;
  }

  /* Query some information */
  printf("Container state: %s\n", c->state(c));
  printf("Container PID: %d\n", c->init_pid(c));

  c->attach(c,salut,NULL,NULL,NULL);


  /* Stop the container */
  if (!c->shutdown(c, 30)) {
    printf("Failed to cleanly shutdown the container, forcing.\n");
    if (!c->stop(c)) {
      fprintf(stderr, "Failed to kill the container.\n");
      goto out;
    }
  }

  ret = 0;
out:
  lxc_container_put(c);
  return ret;
}
