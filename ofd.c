/* ofd.c our first driver 
   This is pretty much a template for
   all linux drivers.

*/

#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

static dev_t first; // Global variable for the first device driver


static int __init ofd_init(void) /* Constructor */
{
	printk(KERN_INFO "Naskar: ofd registered");
	if (alloc_chrdev_region(&first, 0, 3, "Javis") < 0)
	{
		return -1;
	}
	printk(KERN_INFO "<Major, Minor>: <%d, %d>", MAJOR(first), MINOR(first));
	return 0;
}

static void __exit ofd_exit(void) /* Destructor */
{
	unregister_chrdev_region(first, 3);
	printk(KERN_INFO "Alvida: ofd unregistered");
}

module_init(ofd_init);
module_exit(ofd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jsully");
MODULE_DESCRIPTION("Our first driver");
