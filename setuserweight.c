#include <linux/kernel.h>
#include <linux/nospec.h>

#include <linux/kcov.h>
#include <linux/scs.h>

asmlinkage int setuserweight(int uid, int val){
  struct task_struct *p;
  p = find_task_by_vpid(uid);

  if(uid < 0 || val < 0){
    return -1;
  }

  p->rt_priority = val;

  return 0;
}
