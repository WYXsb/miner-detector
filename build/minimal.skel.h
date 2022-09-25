/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __MINIMAL_BPF_SKEL_H__
#define __MINIMAL_BPF_SKEL_H__

#include <stdlib.h>
#include <bpf/libbpf.h>

struct minimal_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *rodata;
		struct bpf_map *bss;
	} maps;
	struct {
		struct bpf_program *handle_tp;
	} progs;
	struct {
		struct bpf_link *handle_tp;
	} links;
	struct minimal_bpf__bss {
		int my_pid;
	} *bss;
	struct minimal_bpf__rodata {
		char handle_tp_____fmt[28];
	} *rodata;
};

static void
minimal_bpf__destroy(struct minimal_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
minimal_bpf__create_skeleton(struct minimal_bpf *obj);

static inline struct minimal_bpf *
minimal_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct minimal_bpf *obj;

	obj = (struct minimal_bpf *)calloc(1, sizeof(*obj));
	if (!obj)
		return NULL;
	if (minimal_bpf__create_skeleton(obj))
		goto err;
	if (bpf_object__open_skeleton(obj->skeleton, opts))
		goto err;

	return obj;
err:
	minimal_bpf__destroy(obj);
	return NULL;
}

static inline struct minimal_bpf *
minimal_bpf__open(void)
{
	return minimal_bpf__open_opts(NULL);
}

static inline int
minimal_bpf__load(struct minimal_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct minimal_bpf *
minimal_bpf__open_and_load(void)
{
	struct minimal_bpf *obj;

	obj = minimal_bpf__open();
	if (!obj)
		return NULL;
	if (minimal_bpf__load(obj)) {
		minimal_bpf__destroy(obj);
		return NULL;
	}
	return obj;
}

static inline int
minimal_bpf__attach(struct minimal_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
minimal_bpf__detach(struct minimal_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline int
minimal_bpf__create_skeleton(struct minimal_bpf *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		return -1;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "minimal_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 2;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "minimal_.rodata";
	s->maps[0].map = &obj->maps.rodata;
	s->maps[0].mmaped = (void **)&obj->rodata;

	s->maps[1].name = "minimal_.bss";
	s->maps[1].map = &obj->maps.bss;
	s->maps[1].mmaped = (void **)&obj->bss;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "handle_tp";
	s->progs[0].prog = &obj->progs.handle_tp;
	s->progs[0].link = &obj->links.handle_tp;

	s->data_sz = 4808;
	s->data = (void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x08\x0d\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x17\0\
\x01\0\x85\0\0\0\x0e\0\0\0\x77\0\0\0\x20\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x61\x11\0\0\0\0\0\0\x5d\x01\x05\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xb7\x02\0\0\x1c\0\0\0\xbf\x03\0\0\0\0\0\0\x85\0\0\0\x06\0\0\0\xb7\0\0\0\0\
\0\0\0\x95\0\0\0\0\0\0\0\x44\x75\x61\x6c\x20\x42\x53\x44\x2f\x47\x50\x4c\0\0\0\
\0\x42\x50\x46\x20\x74\x72\x69\x67\x67\x65\x72\x65\x64\x20\x66\x72\x6f\x6d\x20\
\x50\x49\x44\x20\x25\x64\x2e\x0a\0\x10\0\0\0\0\0\0\0\x58\0\0\0\0\0\0\0\x01\0\
\x50\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\x11\x01\x25\x0e\x13\x05\x03\x0e\x10\
\x17\x1b\x0e\x11\x01\x12\x06\0\0\x02\x34\0\x03\x0e\x49\x13\x3f\x19\x3a\x0b\x3b\
\x0b\x02\x18\0\0\x03\x01\x01\x49\x13\0\0\x04\x21\0\x49\x13\x37\x0b\0\0\x05\x24\
\0\x03\x0e\x3e\x0b\x0b\x0b\0\0\x06\x24\0\x03\x0e\x0b\x0b\x3e\x0b\0\0\x07\x2e\
\x01\x11\x01\x12\x06\x40\x18\x97\x42\x19\x03\x0e\x3a\x0b\x3b\x0b\x27\x19\x49\
\x13\x3f\x19\0\0\x08\x34\0\x03\x0e\x49\x13\x3a\x0b\x3b\x0b\x02\x18\0\0\x09\x05\
\0\x03\x0e\x3a\x0b\x3b\x0b\x49\x13\0\0\x0a\x34\0\x02\x17\x03\x0e\x3a\x0b\x3b\
\x0b\x49\x13\0\0\x0b\x26\0\x49\x13\0\0\x0c\x34\0\x03\x0e\x49\x13\x3a\x0b\x3b\
\x05\0\0\x0d\x0f\0\x49\x13\0\0\x0e\x15\0\x49\x13\x27\x19\0\0\x0f\x16\0\x49\x13\
\x03\x0e\x3a\x0b\x3b\x0b\0\0\x10\x34\0\x03\x0e\x49\x13\x3a\x0b\x3b\x0b\0\0\x11\
\x15\x01\x49\x13\x27\x19\0\0\x12\x05\0\x49\x13\0\0\x13\x18\0\0\0\x14\x0f\0\0\0\
\0\x34\x01\0\0\x04\0\0\0\0\0\x08\x01\0\0\0\0\x0c\0\x2d\0\0\0\0\0\0\0\x5a\0\0\0\
\0\0\0\0\0\0\0\0\x68\0\0\0\x02\x79\0\0\0\x3f\0\0\0\x01\x06\x09\x03\0\0\0\0\0\0\
\0\0\x03\x4b\0\0\0\x04\x52\0\0\0\x0d\0\x05\x81\0\0\0\x06\x01\x06\x86\0\0\0\x08\
\x07\x02\x9a\0\0\0\x6e\0\0\0\x01\x08\x09\x03\0\0\0\0\0\0\0\0\x05\xa1\0\0\0\x05\
\x04\x07\0\0\0\0\0\0\0\0\x68\0\0\0\x01\x5a\x10\x01\0\0\x01\x0b\x6e\0\0\0\x08\
\xa5\0\0\0\xbe\0\0\0\x01\x12\x09\x03\0\0\0\0\0\0\0\0\x09\x1a\x01\0\0\x01\x0b\
\x36\x01\0\0\x0a\0\0\0\0\x1e\x01\0\0\x01\x0d\x6e\0\0\0\0\x03\xca\0\0\0\x04\x52\
\0\0\0\x1c\0\x0b\x4b\0\0\0\x0c\xad\0\0\0\xdb\0\0\0\x03\x6b\x01\x0d\xe0\0\0\0\
\x0e\xe5\0\0\0\x0f\xf0\0\0\0\xdd\0\0\0\x02\x1f\x05\xc6\0\0\0\x07\x08\x10\xe3\0\
\0\0\x02\x01\0\0\x03\xac\x0d\x07\x01\0\0\x11\x18\x01\0\0\x12\x1f\x01\0\0\x12\
\x24\x01\0\0\x13\0\x05\xf4\0\0\0\x05\x08\x0d\xca\0\0\0\x0f\x2f\x01\0\0\x0a\x01\
\0\0\x02\x1b\x05\xfd\0\0\0\x07\x04\x14\0\x55\x62\x75\x6e\x74\x75\x20\x63\x6c\
\x61\x6e\x67\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x31\x32\x2e\x30\x2e\x30\x2d\
\x33\x75\x62\x75\x6e\x74\x75\x31\x7e\x32\x30\x2e\x30\x34\x2e\x35\0\x2f\x68\x6f\
\x6d\x65\x2f\x6a\x69\x65\x2f\x6d\x69\x6e\x65\x72\x5f\x64\x65\x74\x65\x63\x74\
\x6f\x72\x2f\x73\x72\x63\x2f\x63\x2f\x6d\x69\x6e\x69\x6d\x61\x6c\x2e\x62\x70\
\x66\x2e\x63\0\x2f\x68\x6f\x6d\x65\x2f\x6a\x69\x65\x2f\x6d\x69\x6e\x65\x72\x5f\
\x64\x65\x74\x65\x63\x74\x6f\x72\x2f\x62\x75\x69\x6c\x64\0\x4c\x49\x43\x45\x4e\
\x53\x45\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\
\x5f\x54\x59\x50\x45\x5f\x5f\0\x6d\x79\x5f\x70\x69\x64\0\x69\x6e\x74\0\x5f\x5f\
\x5f\x5f\x66\x6d\x74\0\x62\x70\x66\x5f\x67\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\
\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\x64\0\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\
\x20\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x5f\x5f\x75\x36\x34\0\
\x62\x70\x66\x5f\x74\x72\x61\x63\x65\x5f\x70\x72\x69\x6e\x74\x6b\0\x6c\x6f\x6e\
\x67\x20\x69\x6e\x74\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x5f\
\x5f\x75\x33\x32\0\x68\x61\x6e\x64\x6c\x65\x5f\x74\x70\0\x63\x74\x78\0\x70\x69\
\x64\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x10\x01\0\0\x10\x01\0\0\x20\x01\0\0\0\0\
\0\0\0\0\0\x02\0\0\0\0\0\0\0\0\x01\0\0\x0d\x03\0\0\0\x01\0\0\0\x01\0\0\0\x05\0\
\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x09\0\0\0\x01\0\0\x0c\x02\0\0\0\xd1\0\0\0\
\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x05\0\0\0\x07\0\0\0\
\x0d\0\0\0\xd6\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\0\xea\0\0\0\0\0\0\x0e\x06\0\0\
\0\x01\0\0\0\xf2\0\0\0\0\0\0\x0e\x03\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x0a\x05\0\0\
\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0a\0\0\0\x07\0\0\0\x1c\0\0\0\xf9\0\0\0\0\0\0\x0e\
\x0b\0\0\0\0\0\0\0\x0b\x01\0\0\x01\0\0\x0f\0\0\0\0\x09\0\0\0\0\0\0\0\x04\0\0\0\
\x10\x01\0\0\x01\0\0\x0f\0\0\0\0\x0c\0\0\0\0\0\0\0\x1c\0\0\0\x18\x01\0\0\x01\0\
\0\x0f\0\0\0\0\x08\0\0\0\0\0\0\0\x0d\0\0\0\0\x63\x74\x78\0\x69\x6e\x74\0\x68\
\x61\x6e\x64\x6c\x65\x5f\x74\x70\0\x74\x70\x2f\x73\x79\x73\x63\x61\x6c\x6c\x73\
\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x77\x72\x69\x74\x65\0\x2f\x68\x6f\
\x6d\x65\x2f\x6a\x69\x65\x2f\x6d\x69\x6e\x65\x72\x5f\x64\x65\x74\x65\x63\x74\
\x6f\x72\x2f\x73\x72\x63\x2f\x63\x2f\x6d\x69\x6e\x69\x6d\x61\x6c\x2e\x62\x70\
\x66\x2e\x63\0\x09\x69\x6e\x74\x20\x70\x69\x64\x20\x3d\x20\x62\x70\x66\x5f\x67\
\x65\x74\x5f\x63\x75\x72\x72\x65\x6e\x74\x5f\x70\x69\x64\x5f\x74\x67\x69\x64\
\x28\x29\x20\x3e\x3e\x20\x33\x32\x3b\0\x09\x69\x66\x20\x28\x70\x69\x64\x20\x21\
\x3d\x20\x6d\x79\x5f\x70\x69\x64\x29\0\x09\x62\x70\x66\x5f\x70\x72\x69\x6e\x74\
\x6b\x28\x22\x42\x50\x46\x20\x74\x72\x69\x67\x67\x65\x72\x65\x64\x20\x66\x72\
\x6f\x6d\x20\x50\x49\x44\x20\x25\x64\x2e\x5c\x6e\x22\x2c\x20\x70\x69\x64\x29\
\x3b\0\x7d\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\
\x5f\x54\x59\x50\x45\x5f\x5f\0\x4c\x49\x43\x45\x4e\x53\x45\0\x6d\x79\x5f\x70\
\x69\x64\0\x68\x61\x6e\x64\x6c\x65\x5f\x74\x70\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\
\0\x2e\x62\x73\x73\0\x2e\x72\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\x65\
\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x14\0\0\0\x14\0\0\0\x6c\0\0\0\x80\0\0\0\0\0\
\0\0\x08\0\0\0\x13\0\0\0\x01\0\0\0\0\0\0\0\x04\0\0\0\x10\0\0\0\x13\0\0\0\x06\0\
\0\0\0\0\0\0\x2f\0\0\0\x5c\0\0\0\x0c\x34\0\0\x08\0\0\0\x2f\0\0\0\x5c\0\0\0\x27\
\x34\0\0\x10\0\0\0\x2f\0\0\0\x89\0\0\0\x0d\x3c\0\0\x28\0\0\0\x2f\0\0\0\x89\0\0\
\0\x06\x3c\0\0\x30\0\0\0\x2f\0\0\0\x9d\0\0\0\x02\x48\0\0\x58\0\0\0\x2f\0\0\0\
\xcf\0\0\0\x01\x54\0\0\0\0\0\0\0\0\0\x0c\0\0\0\xff\xff\xff\xff\x04\0\x08\0\x08\
\x7c\x0b\0\x14\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\0\0\0\0\0\0\0\xbb\0\0\0\x04\0\
\x8b\0\0\0\x08\x01\x01\xfb\x0e\x0d\0\x01\x01\x01\x01\0\0\0\x01\0\0\x01\x2f\x68\
\x6f\x6d\x65\x2f\x6a\x69\x65\x2f\x6d\x69\x6e\x65\x72\x5f\x64\x65\x74\x65\x63\
\x74\x6f\x72\0\x2f\x75\x73\x72\x2f\x69\x6e\x63\x6c\x75\x64\x65\x2f\x61\x73\x6d\
\x2d\x67\x65\x6e\x65\x72\x69\x63\0\x6c\x69\x62\x62\x70\x66\x2f\x62\x70\x66\0\0\
\x73\x72\x63\x2f\x63\x2f\x6d\x69\x6e\x69\x6d\x61\x6c\x2e\x62\x70\x66\x2e\x63\0\
\x01\0\0\x69\x6e\x74\x2d\x6c\x6c\x36\x34\x2e\x68\0\x02\0\0\x62\x70\x66\x5f\x68\
\x65\x6c\x70\x65\x72\x5f\x64\x65\x66\x73\x2e\x68\0\x03\0\0\0\0\x09\x02\0\0\0\0\
\0\0\0\0\x03\x0b\x01\x05\x0c\x0a\x13\x05\x27\x06\x20\x05\x0d\x06\x22\x05\x06\
\x06\x3c\x05\x02\x06\x23\x05\x01\x5b\x02\x02\0\x01\x01\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xc7\0\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xfe\0\0\0\0\0\x03\0\x58\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x22\0\0\0\x01\0\x07\
\0\0\0\0\0\0\0\0\0\x1c\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x03\0\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x09\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x03\0\x0c\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\
\x11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x13\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xf6\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x0d\0\0\0\0\0\0\0\x44\0\0\0\
\x12\0\x03\0\0\0\0\0\0\0\0\0\x68\0\0\0\0\0\0\0\xb5\0\0\0\x11\0\x06\0\0\0\0\0\0\
\0\0\0\x04\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x0d\0\0\0\x30\0\0\0\0\0\0\
\0\x01\0\0\0\x05\0\0\0\x06\0\0\0\0\0\0\0\x0a\0\0\0\x07\0\0\0\x0c\0\0\0\0\0\0\0\
\x0a\0\0\0\x08\0\0\0\x12\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x16\0\0\0\0\0\0\0\
\x0a\0\0\0\x0a\0\0\0\x1a\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x1e\0\0\0\0\0\0\0\
\x01\0\0\0\x04\0\0\0\x2b\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x37\0\0\0\0\0\0\0\
\x01\0\0\0\x0b\0\0\0\x4c\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x53\0\0\0\0\0\0\0\
\x0a\0\0\0\x08\0\0\0\x5a\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x66\0\0\0\0\0\0\0\
\x01\0\0\0\x0d\0\0\0\x6f\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x76\0\0\0\0\0\0\0\
\x01\0\0\0\x04\0\0\0\x84\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x8f\0\0\0\0\0\0\0\
\x0a\0\0\0\x08\0\0\0\x9b\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\xa4\0\0\0\0\0\0\0\
\x0a\0\0\0\x08\0\0\0\xaf\0\0\0\0\0\0\0\x0a\0\0\0\x06\0\0\0\xb3\0\0\0\0\0\0\0\
\x0a\0\0\0\x08\0\0\0\xd0\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\xea\0\0\0\0\0\0\0\
\x0a\0\0\0\x08\0\0\0\xf1\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\xf8\0\0\0\0\0\0\0\
\x0a\0\0\0\x08\0\0\0\x19\x01\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x29\x01\0\0\0\0\0\
\0\x0a\0\0\0\x08\0\0\0\x30\x01\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\xf0\0\0\0\0\0\0\
\0\0\0\0\0\x0d\0\0\0\x08\x01\0\0\0\0\0\0\x0a\0\0\0\x05\0\0\0\x20\x01\0\0\0\0\0\
\0\0\0\0\0\x0b\0\0\0\x2c\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x40\0\0\0\0\0\0\0\0\0\
\0\0\x04\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x60\0\0\0\0\0\0\0\0\0\0\0\
\x04\0\0\0\x70\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\x04\0\
\0\0\x90\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x14\0\0\0\0\0\0\0\x0a\0\0\0\x09\0\0\0\
\x18\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\x98\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\
\x0c\x0b\x03\0\x2e\x64\x65\x62\x75\x67\x5f\x61\x62\x62\x72\x65\x76\0\x2e\x74\
\x65\x78\x74\0\x2e\x72\x65\x6c\x2e\x42\x54\x46\x2e\x65\x78\x74\0\x68\x61\x6e\
\x64\x6c\x65\x5f\x74\x70\x2e\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x2e\x62\x73\x73\0\
\x2e\x64\x65\x62\x75\x67\x5f\x73\x74\x72\0\x68\x61\x6e\x64\x6c\x65\x5f\x74\x70\
\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x69\x6e\x66\x6f\0\x2e\x6c\x6c\
\x76\x6d\x5f\x61\x64\x64\x72\x73\x69\x67\0\x2e\x72\x65\x6c\x74\x70\x2f\x73\x79\
\x73\x63\x61\x6c\x6c\x73\x2f\x73\x79\x73\x5f\x65\x6e\x74\x65\x72\x5f\x77\x72\
\x69\x74\x65\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\
\x75\x67\x5f\x6c\x69\x6e\x65\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x66\
\x72\x61\x6d\x65\0\x6d\x79\x5f\x70\x69\x64\0\x2e\x64\x65\x62\x75\x67\x5f\x6c\
\x6f\x63\0\x6d\x69\x6e\x69\x6d\x61\x6c\x2e\x62\x70\x66\x2e\x63\0\x2e\x73\x74\
\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x72\x6f\x64\x61\x74\x61\0\
\x2e\x72\x65\x6c\x2e\x42\x54\x46\0\x4c\x49\x43\x45\x4e\x53\x45\0\x4c\x42\x42\
\x30\x5f\x32\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd5\0\0\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\x0c\0\0\0\0\0\0\x05\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\0\0\0\x01\0\0\0\x06\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x40\0\0\0\0\0\0\0\x68\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x6c\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x09\
\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x16\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\
\0\0\0\0\x8c\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa8\0\0\0\0\0\0\
\0\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x34\0\0\
\0\x08\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\0\0\0\0\0\0\0\x04\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe5\0\0\0\x01\0\0\0\x02\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\0\0\0\0\0\0\0\x1c\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbc\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xd4\0\0\0\0\0\0\0\x23\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf7\0\
\0\0\0\0\0\0\xe8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x52\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xdf\x01\0\0\0\0\0\0\x38\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4e\0\0\0\
\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x80\x09\0\0\0\0\0\0\xb0\x01\0\0\0\0\
\0\0\x16\0\0\0\x0a\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x39\0\0\0\x01\0\0\
\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x17\x03\0\0\0\0\0\0\x22\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\xf1\0\0\0\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x39\x04\0\0\0\0\0\0\x48\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xed\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x30\x0b\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x16\0\0\0\x0d\0\0\0\x08\0\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\x19\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x81\x06\0\0\0\0\0\0\xa0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x15\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x0b\0\0\0\0\
\0\0\x70\0\0\0\0\0\0\0\x16\0\0\0\x0f\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\
\xa8\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x07\0\0\0\0\0\0\x28\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa4\0\0\0\x09\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x0b\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x16\
\0\0\0\x11\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x98\0\0\0\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\x07\0\0\0\0\0\0\xbf\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x94\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\xf0\x0b\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x16\0\0\0\x13\0\0\0\x08\0\0\0\
\0\0\0\0\x10\0\0\0\0\0\0\0\x5e\0\0\0\x03\x4c\xff\x6f\0\0\0\x80\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x0c\0\0\0\0\0\0\x03\0\0\0\0\0\0\0\x16\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xdd\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x08\
\0\0\0\0\0\0\x50\x01\0\0\0\0\0\0\x01\0\0\0\x0b\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\
\0\0\0\0\0";

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -1;
}

#endif /* __MINIMAL_BPF_SKEL_H__ */
