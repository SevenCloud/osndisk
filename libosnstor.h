#ifndef LIBOSNSTOR_H_
#define LIBOSNSTOR_H_
#include"list.h"

struct scsi_host {
	struct list_head host_entry;

	/* device list of this host*/
	struct list_head dev_list;

	/* host unique identifier */
	unsigned int host_id;

	/*device name, for example host1,host2 */
	const char *devname;

	/* qla2xxx/iscsi_tcp/... */
	const char *driver_type;

	unsigned int transport_type;

	const char *port_name;
	uint32_t port_id;
};

struct scsi_dev {
	struct list_head dev_entry;

	unsigned int host, channel, target, lun;
	unsigned int major, minor;

	const char *vendor;
	const char *model;
	const char *rev;

	char type;
	char scsi_level;

	unsigned sector_size;

	/* for block device */
	uint64_t size;
	unsigned int queue_type;
	unsigned int queue_depth;

	unsigned int status;
};
#endif /* LIBOSNSTOR_H_ */

