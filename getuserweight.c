#include <linux/kernel.h>
#include <linux/nospec.h>

#include <linux/kcov.h>
#include <linux/scs.h>

asmlinkage int getuserweight(int uid){
  struct task_struct *p;
  p = find_task_by_vpid(uid);
  if(uid < 0){
    return -1;
  }

  return p->rt_priority;
}

/**
struct sched_attr attr = {
  .sched_policy   = policy,
  .sched_priority = param->sched_priority,
  .sched_nice	= PRIO_TO_NICE(p->static_prio),
};
**/
