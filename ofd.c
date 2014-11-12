/* ofd.c our first driver 
   This is pretty much a template for
   all linux drivers.

*/

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>

static int __init ofd_init(void) /* Constructor */
{
	printk(KERN_INFO "Naskar: ofd registered");
	return 0;
}

static void __exit ofd_exit(void) /* Destructor */
{
	printk(KERN_INFO "Alvida: ofd unregistered");
}

module_init(ofd_init);
module_exit(ofd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jsully");
MODULE_DESCRIPTION("Our first driver");
