/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __UPROBE_BPF_SKEL_H__
#define __UPROBE_BPF_SKEL_H__

#include <stdlib.h>
#include <bpf/libbpf.h>

struct uprobe_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *uprobe;
		struct bpf_program *uretprobe;
	} progs;
	struct {
		struct bpf_link *uprobe;
		struct bpf_link *uretprobe;
	} links;
	struct uprobe_bpf__rodata {
		char ____uprobe_____fmt[30];
		char ____uretprobe_____fmt[26];
	} *rodata;
};

static void
uprobe_bpf__destroy(struct uprobe_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
uprobe_bpf__create_skeleton(struct uprobe_bpf *obj);

static inline struct uprobe_bpf *
uprobe_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct uprobe_bpf *obj;

	obj = (struct uprobe_bpf *)calloc(1, sizeof(*obj));
	if (!obj)
		return NULL;
	if (uprobe_bpf__create_skeleton(obj))
		goto err;
	if (bpf_object__open_skeleton(obj->skeleton, opts))
		goto err;

	return obj;
err:
	uprobe_bpf__destroy(obj);
	return NULL;
}

static inline struct uprobe_bpf *
uprobe_bpf__open(void)
{
	return uprobe_bpf__open_opts(NULL);
}

static inline int
uprobe_bpf__load(struct uprobe_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct uprobe_bpf *
uprobe_bpf__open_and_load(void)
{
	struct uprobe_bpf *obj;

	obj = uprobe_bpf__open();
	if (!obj)
		return NULL;
	if (uprobe_bpf__load(obj)) {
		uprobe_bpf__destroy(obj);
		return NULL;
	}
	return obj;
}

static inline int
uprobe_bpf__attach(struct uprobe_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
uprobe_bpf__detach(struct uprobe_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline int
uprobe_bpf__create_skeleton(struct uprobe_bpf *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		return -1;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "uprobe_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 1;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "uprobe_b.rodata";
	s->maps[0].map = &obj->maps.rodata;
	s->maps[0].mmaped = (void **)&obj->rodata;

	/* programs */
	s->prog_cnt = 2;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "uprobe";
	s->progs[0].prog = &obj->progs.uprobe;
	s->progs[0].link = &obj->links.uprobe;

	s->progs[1].name = "uretprobe";
	s->progs[1].prog = &obj->progs.uretprobe;
	s->progs[1].link = &obj->links.uretprobe;

	s->data_sz = 7168;
	s->data = (void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x40\x15\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x1b\0\
\x01\0\x79\x14\x68\0\0\0\0\0\x79\x13\x70\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xb7\x02\0\0\x1e\0\0\0\x85\0\0\0\x06\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\
\0\0\0\0\x79\x13\x50\0\0\0\0\0\x18\x01\0\0\x1e\0\0\0\0\0\0\0\0\0\0\0\xb7\x02\0\
\0\x1a\0\0\0\x85\0\0\0\x06\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x44\x75\
\x61\x6c\x20\x42\x53\x44\x2f\x47\x50\x4c\0\x55\x50\x52\x4f\x42\x45\x20\x45\x4e\
\x54\x52\x59\x3a\x20\x61\x20\x3d\x20\x25\x64\x2c\x20\x62\x20\x3d\x20\x25\x64\
\x0a\0\x55\x50\x52\x4f\x42\x45\x20\x45\x58\x49\x54\x3a\x20\x72\x65\x74\x75\x72\
\x6e\x20\x3d\x20\x25\x64\x0a\0\xff\xff\xff\xff\xff\xff\xff\xff\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x01\0\x51\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xff\xff\xff\xff\xff\xff\xff\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x18\0\0\0\0\0\
\0\0\x01\0\x51\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\x11\x01\x25\x0e\x13\x05\x03\
\x0e\x10\x17\x1b\x0e\x11\x01\x55\x17\0\0\x02\x34\0\x03\x0e\x49\x13\x3f\x19\x3a\
\x0b\x3b\x0b\x02\x18\0\0\x03\x01\x01\x49\x13\0\0\x04\x21\0\x49\x13\x37\x0b\0\0\
\x05\x24\0\x03\x0e\x3e\x0b\x0b\x0b\0\0\x06\x24\0\x03\x0e\x0b\x0b\x3e\x0b\0\0\
\x07\x2e\x01\0\0\x08\x34\0\x03\x0e\x49\x13\x3a\x0b\x3b\x0b\x02\x18\0\0\x09\x26\
\0\x49\x13\0\0\x0a\x34\0\x03\x0e\x49\x13\x3a\x0b\x3b\x0b\0\0\x0b\x0f\0\x49\x13\
\0\0\x0c\x15\x01\x49\x13\x27\x19\0\0\x0d\x05\0\x49\x13\0\0\x0e\x18\0\0\0\x0f\
\x16\0\x49\x13\x03\x0e\x3a\x0b\x3b\x0b\0\0\x10\x0f\0\0\0\x11\x2e\x01\x03\x0e\
\x3a\x0b\x3b\x0b\x27\x19\x49\x13\x20\x0b\0\0\x12\x05\0\x03\x0e\x3a\x0b\x3b\x0b\
\x49\x13\0\0\x13\x13\x01\x03\x0e\x0b\x0b\x3a\x0b\x3b\x0b\0\0\x14\x0d\0\x03\x0e\
\x49\x13\x3a\x0b\x3b\x0b\x38\x0b\0\0\x15\x2e\x01\x11\x01\x12\x06\x40\x18\x97\
\x42\x19\x03\x0e\x3a\x0b\x3b\x0b\x27\x19\x49\x13\x3f\x19\0\0\x16\x05\0\x02\x17\
\x03\x0e\x3a\x0b\x3b\x0b\x49\x13\0\0\x17\x1d\x01\x31\x13\x11\x01\x12\x06\x58\
\x0b\x59\x0b\x57\x0b\0\0\x18\x05\0\x31\x13\0\0\x19\x05\0\x02\x18\x31\x13\0\0\0\
\xe5\x02\0\0\x04\0\0\0\0\0\x08\x01\0\0\0\0\x0c\0\x2d\0\0\0\0\0\0\0\x59\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x02\x78\0\0\0\x3f\0\0\0\x01\x08\x09\x03\0\0\0\0\0\0\0\0\
\x03\x4b\0\0\0\x04\x52\0\0\0\x0d\0\x05\x80\0\0\0\x06\x01\x06\x85\0\0\0\x08\x07\
\x07\x08\x99\0\0\0\x70\0\0\0\x01\x0d\x09\x03\0\0\0\0\0\0\0\0\0\x03\x7c\0\0\0\
\x04\x52\0\0\0\x1e\0\x09\x4b\0\0\0\x0a\xa1\0\0\0\x8c\0\0\0\x03\xac\x0b\x91\0\0\
\0\x0c\xa2\0\0\0\x0d\xa9\0\0\0\x0d\xae\0\0\0\x0e\0\x05\xb2\0\0\0\x05\x08\x0b\
\x7c\0\0\0\x0f\xb9\0\0\0\xc8\0\0\0\x02\x1b\x05\xbb\0\0\0\x07\x04\x07\x08\x99\0\
\0\0\xd7\0\0\0\x01\x14\x09\x03\x1e\0\0\0\0\0\0\0\0\x03\x7c\0\0\0\x04\x52\0\0\0\
\x1a\0\x10\x11\xce\0\0\0\x01\x0b\x12\x01\0\0\x01\x12\xdd\0\0\0\x01\x0b\x19\x01\
\0\0\x12\x53\x01\0\0\x01\x0b\x12\x01\0\0\x12\x55\x01\0\0\x01\x0b\x12\x01\0\0\0\
\x05\xd9\0\0\0\x05\x04\x0b\x1e\x01\0\0\x13\x4b\x01\0\0\xa8\x04\x29\x14\xe1\0\0\
\0\x23\x02\0\0\x04\x2e\0\x14\xf7\0\0\0\x23\x02\0\0\x04\x2f\x08\x14\xfb\0\0\0\
\x23\x02\0\0\x04\x30\x10\x14\xff\0\0\0\x23\x02\0\0\x04\x31\x18\x14\x03\x01\0\0\
\x23\x02\0\0\x04\x32\x20\x14\x07\x01\0\0\x23\x02\0\0\x04\x33\x28\x14\x0b\x01\0\
\0\x23\x02\0\0\x04\x35\x30\x14\x0f\x01\0\0\x23\x02\0\0\x04\x36\x38\x14\x13\x01\
\0\0\x23\x02\0\0\x04\x37\x40\x14\x16\x01\0\0\x23\x02\0\0\x04\x38\x48\x14\x19\
\x01\0\0\x23\x02\0\0\x04\x39\x50\x14\x1d\x01\0\0\x23\x02\0\0\x04\x3a\x58\x14\
\x21\x01\0\0\x23\x02\0\0\x04\x3b\x60\x14\x25\x01\0\0\x23\x02\0\0\x04\x3c\x68\
\x14\x29\x01\0\0\x23\x02\0\0\x04\x3d\x70\x14\x2d\x01\0\0\x23\x02\0\0\x04\x42\
\x78\x14\x36\x01\0\0\x23\x02\0\0\x04\x44\x80\x14\x3a\x01\0\0\x23\x02\0\0\x04\
\x45\x88\x14\x3d\x01\0\0\x23\x02\0\0\x04\x46\x90\x14\x44\x01\0\0\x23\x02\0\0\
\x04\x47\x98\x14\x48\x01\0\0\x23\x02\0\0\x04\x48\xa0\0\x05\xe5\0\0\0\x07\x08\
\x15\0\0\0\0\0\0\0\0\x40\0\0\0\x01\x5a\x69\x01\0\0\x01\x0b\x12\x01\0\0\x16\0\0\
\0\0\xdd\0\0\0\x01\x0b\x19\x01\0\0\x17\xe4\0\0\0\x10\0\0\0\0\0\0\0\x20\0\0\0\
\x01\x0b\x05\x18\xf0\0\0\0\x19\x01\x53\xfb\0\0\0\x19\x01\x54\x06\x01\0\0\0\0\
\x11\x57\x01\0\0\x01\x12\x12\x01\0\0\x01\x12\xdd\0\0\0\x01\x12\x19\x01\0\0\x12\
\x65\x01\0\0\x01\x12\x12\x01\0\0\0\x15\0\0\0\0\0\0\0\0\x38\0\0\0\x01\x5a\x70\
\x01\0\0\x01\x12\x12\x01\0\0\x16\x33\0\0\0\xdd\0\0\0\x01\x12\x19\x01\0\0\x17\
\x7b\x02\0\0\x08\0\0\0\0\0\0\0\x20\0\0\0\x01\x12\x05\x18\x87\x02\0\0\x19\x01\
\x53\x92\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x55\x62\x75\x6e\x74\x75\x20\x63\
\x6c\x61\x6e\x67\x20\x76\x65\x72\x73\x69\x6f\x6e\x20\x31\x32\x2e\x30\x2e\x30\
\x2d\x33\x75\x62\x75\x6e\x74\x75\x31\x7e\x32\x30\x2e\x30\x34\x2e\x35\0\x2f\x68\
\x6f\x6d\x65\x2f\x6a\x69\x65\x2f\x6d\x69\x6e\x65\x72\x5f\x64\x65\x74\x65\x63\
\x74\x6f\x72\x2f\x73\x72\x63\x2f\x63\x2f\x75\x70\x72\x6f\x62\x65\x2e\x62\x70\
\x66\x2e\x63\0\x2f\x68\x6f\x6d\x65\x2f\x6a\x69\x65\x2f\x6d\x69\x6e\x65\x72\x5f\
\x64\x65\x74\x65\x63\x74\x6f\x72\x2f\x62\x75\x69\x6c\x64\0\x4c\x49\x43\x45\x4e\
\x53\x45\0\x63\x68\x61\x72\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\
\x5f\x54\x59\x50\x45\x5f\x5f\0\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x62\x70\x66\x5f\
\x74\x72\x61\x63\x65\x5f\x70\x72\x69\x6e\x74\x6b\0\x6c\x6f\x6e\x67\x20\x69\x6e\
\x74\0\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x5f\x5f\x75\x33\x32\0\
\x5f\x5f\x5f\x5f\x75\x70\x72\x6f\x62\x65\0\x69\x6e\x74\0\x63\x74\x78\0\x72\x31\
\x35\0\x6c\x6f\x6e\x67\x20\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\
\x72\x31\x34\0\x72\x31\x33\0\x72\x31\x32\0\x72\x62\x70\0\x72\x62\x78\0\x72\x31\
\x31\0\x72\x31\x30\0\x72\x39\0\x72\x38\0\x72\x61\x78\0\x72\x63\x78\0\x72\x64\
\x78\0\x72\x73\x69\0\x72\x64\x69\0\x6f\x72\x69\x67\x5f\x72\x61\x78\0\x72\x69\
\x70\0\x63\x73\0\x65\x66\x6c\x61\x67\x73\0\x72\x73\x70\0\x73\x73\0\x70\x74\x5f\
\x72\x65\x67\x73\0\x61\0\x62\0\x5f\x5f\x5f\x5f\x75\x72\x65\x74\x70\x72\x6f\x62\
\x65\0\x72\x65\x74\0\x75\x70\x72\x6f\x62\x65\0\x75\x72\x65\x74\x70\x72\x6f\x62\
\x65\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x54\x02\0\0\x54\x02\0\0\xdd\x01\0\0\0\0\
\0\0\0\0\0\x02\x02\0\0\0\x01\0\0\0\x15\0\0\x04\xa8\0\0\0\x09\0\0\0\x03\0\0\0\0\
\0\0\0\x0d\0\0\0\x03\0\0\0\x40\0\0\0\x11\0\0\0\x03\0\0\0\x80\0\0\0\x15\0\0\0\
\x03\0\0\0\xc0\0\0\0\x19\0\0\0\x03\0\0\0\0\x01\0\0\x1d\0\0\0\x03\0\0\0\x40\x01\
\0\0\x21\0\0\0\x03\0\0\0\x80\x01\0\0\x25\0\0\0\x03\0\0\0\xc0\x01\0\0\x29\0\0\0\
\x03\0\0\0\0\x02\0\0\x2c\0\0\0\x03\0\0\0\x40\x02\0\0\x2f\0\0\0\x03\0\0\0\x80\
\x02\0\0\x33\0\0\0\x03\0\0\0\xc0\x02\0\0\x37\0\0\0\x03\0\0\0\0\x03\0\0\x3b\0\0\
\0\x03\0\0\0\x40\x03\0\0\x3f\0\0\0\x03\0\0\0\x80\x03\0\0\x43\0\0\0\x03\0\0\0\
\xc0\x03\0\0\x4c\0\0\0\x03\0\0\0\0\x04\0\0\x50\0\0\0\x03\0\0\0\x40\x04\0\0\x53\
\0\0\0\x03\0\0\0\x80\x04\0\0\x5a\0\0\0\x03\0\0\0\xc0\x04\0\0\x5e\0\0\0\x03\0\0\
\0\0\x05\0\0\x61\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x0d\x05\0\
\0\0\x73\0\0\0\x01\0\0\0\x77\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\0\x01\x7b\0\0\0\
\x01\0\0\x0c\x04\0\0\0\0\0\0\0\x01\0\0\x0d\x05\0\0\0\x73\0\0\0\x01\0\0\0\x14\
\x01\0\0\x01\0\0\x0c\x07\0\0\0\x83\x01\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\0\0\
\0\0\0\0\0\x03\0\0\0\0\x09\0\0\0\x0b\0\0\0\x0d\0\0\0\x88\x01\0\0\0\0\0\x01\x04\
\0\0\0\x20\0\0\0\x9c\x01\0\0\0\0\0\x0e\x0a\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x0a\
\x09\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0d\0\0\0\x0b\0\0\0\x1e\0\0\0\xa4\x01\0\0\
\0\0\0\x0e\x0e\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\0\x0d\0\0\0\x0b\0\0\0\x1a\
\0\0\0\xb7\x01\0\0\0\0\0\x0e\x10\0\0\0\0\0\0\0\xcd\x01\0\0\x02\0\0\x0f\0\0\0\0\
\x0f\0\0\0\0\0\0\0\x1e\0\0\0\x11\0\0\0\x1e\0\0\0\x1a\0\0\0\xd5\x01\0\0\x01\0\0\
\x0f\0\0\0\0\x0c\0\0\0\0\0\0\0\x0d\0\0\0\0\x70\x74\x5f\x72\x65\x67\x73\0\x72\
\x31\x35\0\x72\x31\x34\0\x72\x31\x33\0\x72\x31\x32\0\x72\x62\x70\0\x72\x62\x78\
\0\x72\x31\x31\0\x72\x31\x30\0\x72\x39\0\x72\x38\0\x72\x61\x78\0\x72\x63\x78\0\
\x72\x64\x78\0\x72\x73\x69\0\x72\x64\x69\0\x6f\x72\x69\x67\x5f\x72\x61\x78\0\
\x72\x69\x70\0\x63\x73\0\x65\x66\x6c\x61\x67\x73\0\x72\x73\x70\0\x73\x73\0\x6c\
\x6f\x6e\x67\x20\x75\x6e\x73\x69\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x63\x74\x78\
\0\x69\x6e\x74\0\x75\x70\x72\x6f\x62\x65\0\x75\x70\x72\x6f\x62\x65\x2f\x66\x75\
\x6e\x63\0\x2f\x68\x6f\x6d\x65\x2f\x6a\x69\x65\x2f\x6d\x69\x6e\x65\x72\x5f\x64\
\x65\x74\x65\x63\x74\x6f\x72\x2f\x73\x72\x63\x2f\x63\x2f\x75\x70\x72\x6f\x62\
\x65\x2e\x62\x70\x66\x2e\x63\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x4b\x50\x52\x4f\
\x42\x45\x28\x75\x70\x72\x6f\x62\x65\x2c\x20\x69\x6e\x74\x20\x61\x2c\x20\x69\
\x6e\x74\x20\x62\x29\0\x09\x62\x70\x66\x5f\x70\x72\x69\x6e\x74\x6b\x28\x22\x55\
\x50\x52\x4f\x42\x45\x20\x45\x4e\x54\x52\x59\x3a\x20\x61\x20\x3d\x20\x25\x64\
\x2c\x20\x62\x20\x3d\x20\x25\x64\x5c\x6e\x22\x2c\x20\x61\x2c\x20\x62\x29\x3b\0\
\x75\x72\x65\x74\x70\x72\x6f\x62\x65\0\x75\x72\x65\x74\x70\x72\x6f\x62\x65\x2f\
\x66\x75\x6e\x63\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x4b\x52\x45\x54\x50\x52\x4f\
\x42\x45\x28\x75\x72\x65\x74\x70\x72\x6f\x62\x65\x2c\x20\x69\x6e\x74\x20\x72\
\x65\x74\x29\0\x09\x62\x70\x66\x5f\x70\x72\x69\x6e\x74\x6b\x28\x22\x55\x50\x52\
\x4f\x42\x45\x20\x45\x58\x49\x54\x3a\x20\x72\x65\x74\x75\x72\x6e\x20\x3d\x20\
\x25\x64\x5c\x6e\x22\x2c\x20\x72\x65\x74\x29\x3b\0\x63\x68\x61\x72\0\x5f\x5f\
\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\x50\x45\x5f\x5f\0\x4c\x49\
\x43\x45\x4e\x53\x45\0\x5f\x5f\x5f\x5f\x75\x70\x72\x6f\x62\x65\x2e\x5f\x5f\x5f\
\x5f\x66\x6d\x74\0\x5f\x5f\x5f\x5f\x75\x72\x65\x74\x70\x72\x6f\x62\x65\x2e\x5f\
\x5f\x5f\x5f\x66\x6d\x74\0\x2e\x72\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\
\x73\x65\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x24\0\0\0\x24\0\0\0\x74\0\0\0\x98\0\
\0\0\0\0\0\0\x08\0\0\0\x82\0\0\0\x01\0\0\0\0\0\0\0\x06\0\0\0\x1e\x01\0\0\x01\0\
\0\0\0\0\0\0\x08\0\0\0\x10\0\0\0\x82\0\0\0\x03\0\0\0\0\0\0\0\x8e\0\0\0\xba\0\0\
\0\x05\x2c\0\0\x10\0\0\0\x8e\0\0\0\xdf\0\0\0\x02\x34\0\0\x30\0\0\0\x8e\0\0\0\
\xba\0\0\0\x05\x2c\0\0\x1e\x01\0\0\x03\0\0\0\0\0\0\0\x8e\0\0\0\x2d\x01\0\0\x05\
\x48\0\0\x08\0\0\0\x8e\0\0\0\x53\x01\0\0\x02\x50\0\0\x28\0\0\0\x8e\0\0\0\x2d\
\x01\0\0\x05\x48\0\0\0\0\0\0\x0c\0\0\0\xff\xff\xff\xff\x04\0\x08\0\x08\x7c\x0b\
\0\x14\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x14\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x38\0\0\0\0\0\0\0\xe7\0\0\0\x04\0\xa7\0\0\0\x08\x01\x01\xfb\x0e\x0d\
\0\x01\x01\x01\x01\0\0\0\x01\0\0\x01\x2f\x68\x6f\x6d\x65\x2f\x6a\x69\x65\x2f\
\x6d\x69\x6e\x65\x72\x5f\x64\x65\x74\x65\x63\x74\x6f\x72\0\x2f\x75\x73\x72\x2f\
\x69\x6e\x63\x6c\x75\x64\x65\x2f\x61\x73\x6d\x2d\x67\x65\x6e\x65\x72\x69\x63\0\
\x6c\x69\x62\x62\x70\x66\x2f\x62\x70\x66\0\x2f\x75\x73\x72\x2f\x69\x6e\x63\x6c\
\x75\x64\x65\x2f\x61\x73\x6d\0\0\x73\x72\x63\x2f\x63\x2f\x75\x70\x72\x6f\x62\
\x65\x2e\x62\x70\x66\x2e\x63\0\x01\0\0\x69\x6e\x74\x2d\x6c\x6c\x36\x34\x2e\x68\
\0\x02\0\0\x62\x70\x66\x5f\x68\x65\x6c\x70\x65\x72\x5f\x64\x65\x66\x73\x2e\x68\
\0\x03\0\0\x70\x74\x72\x61\x63\x65\x2e\x68\0\x04\0\0\0\0\x09\x02\0\0\0\0\0\0\0\
\0\x03\x0a\x01\x05\x05\x0a\x01\x05\x02\x30\x05\x05\x48\x02\x02\0\x01\x01\0\x09\
\x02\0\0\0\0\0\0\0\0\x03\x11\x01\x05\x05\x0a\x01\x05\x02\x22\x05\x05\x48\x02\
\x02\0\x01\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf2\0\
\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x22\0\0\0\x01\0\x08\0\0\0\0\
\0\0\0\0\0\x1e\0\0\0\0\0\0\0\x35\0\0\0\x01\0\x08\0\x1e\0\0\0\0\0\0\0\x1a\0\0\0\
\0\0\0\0\0\0\0\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x05\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x03\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x0b\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x0e\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x03\0\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x15\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x17\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x20\x01\0\0\x11\0\x07\0\0\0\0\0\0\0\0\0\x0d\0\0\0\0\0\0\0\xaf\0\0\0\
\x12\0\x03\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xb6\0\0\0\x12\0\x05\0\0\0\0\0\0\
\0\0\0\x38\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\
\0\x01\0\0\0\x06\0\0\0\x08\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\x3b\0\0\0\0\0\0\0\
\x01\0\0\0\x05\0\0\0\x06\0\0\0\0\0\0\0\x0a\0\0\0\x08\0\0\0\x0c\0\0\0\0\0\0\0\
\x0a\0\0\0\x0a\0\0\0\x12\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x16\0\0\0\0\0\0\0\
\x0a\0\0\0\x0c\0\0\0\x1a\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x26\0\0\0\0\0\0\0\
\x0a\0\0\0\x09\0\0\0\x2b\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x37\0\0\0\0\0\0\0\
\x01\0\0\0\x0d\0\0\0\x4c\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x53\0\0\0\0\0\0\0\
\x0a\0\0\0\x0a\0\0\0\x5b\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x67\0\0\0\0\0\0\0\
\x01\0\0\0\x06\0\0\0\x82\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xa3\0\0\0\0\0\0\0\
\x0a\0\0\0\x0a\0\0\0\xb3\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xba\0\0\0\0\0\0\0\
\x0a\0\0\0\x0a\0\0\0\xc2\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xce\0\0\0\0\0\0\0\
\x01\0\0\0\x06\0\0\0\xe5\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xf1\0\0\0\0\0\0\0\
\x0a\0\0\0\x0a\0\0\0\xfc\0\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x07\x01\0\0\0\0\0\0\
\x0a\0\0\0\x0a\0\0\0\x13\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x1f\x01\0\0\0\0\0\
\0\x0a\0\0\0\x0a\0\0\0\x27\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x33\x01\0\0\0\0\
\0\0\x0a\0\0\0\x0a\0\0\0\x3f\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x4b\x01\0\0\0\
\0\0\0\x0a\0\0\0\x0a\0\0\0\x57\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x63\x01\0\0\
\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x6f\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x7b\x01\0\
\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x87\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x93\x01\
\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x9f\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xab\
\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xb7\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\
\xc3\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xcf\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\
\0\xdb\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xe7\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\
\0\0\xf3\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xff\x01\0\0\0\0\0\0\x0a\0\0\0\x0a\
\0\0\0\x0b\x02\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x17\x02\0\0\0\0\0\0\x0a\0\0\0\
\x0a\0\0\0\x24\x02\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x2b\x02\0\0\0\0\0\0\x01\0\0\
\0\x04\0\0\0\x39\x02\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x44\x02\0\0\0\0\0\0\x0a\0\
\0\0\x07\0\0\0\x48\x02\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x57\x02\0\0\0\0\0\0\x01\
\0\0\0\x04\0\0\0\x7c\x02\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x88\x02\0\0\0\0\0\0\
\x0a\0\0\0\x0a\0\0\0\x93\x02\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\x9f\x02\0\0\0\0\0\
\0\x01\0\0\0\x05\0\0\0\xad\x02\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xb8\x02\0\0\0\0\
\0\0\x0a\0\0\0\x07\0\0\0\xbc\x02\0\0\0\0\0\0\x0a\0\0\0\x0a\0\0\0\xcb\x02\0\0\0\
\0\0\0\x01\0\0\0\x05\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\x08\0\0\0\0\0\0\
\0\x01\0\0\0\x04\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x18\0\0\0\0\0\0\0\
\x01\0\0\0\x05\0\0\0\x40\x02\0\0\0\0\0\0\x0a\0\0\0\x06\0\0\0\x4c\x02\0\0\0\0\0\
\0\x0a\0\0\0\x06\0\0\0\x64\x02\0\0\0\0\0\0\0\0\0\0\x0d\0\0\0\x2c\0\0\0\0\0\0\0\
\0\0\0\0\x04\0\0\0\x3c\0\0\0\0\0\0\0\0\0\0\0\x05\0\0\0\x50\0\0\0\0\0\0\0\0\0\0\
\0\x04\0\0\0\x60\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\x70\0\0\0\0\0\0\0\0\0\0\0\x04\
\0\0\0\x88\0\0\0\0\0\0\0\0\0\0\0\x05\0\0\0\x98\0\0\0\0\0\0\0\0\0\0\0\x05\0\0\0\
\xa8\0\0\0\0\0\0\0\0\0\0\0\x05\0\0\0\x14\0\0\0\0\0\0\0\x0a\0\0\0\x0b\0\0\0\x18\
\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\x2c\0\0\0\0\0\0\0\x0a\0\0\0\x0b\0\0\0\x30\0\
\0\0\0\0\0\0\x01\0\0\0\x05\0\0\0\xb4\0\0\0\0\0\0\0\x01\0\0\0\x04\0\0\0\xd1\0\0\
\0\0\0\0\0\x01\0\0\0\x05\0\0\0\x0e\x0f\x0d\x02\x03\0\x2e\x64\x65\x62\x75\x67\
\x5f\x61\x62\x62\x72\x65\x76\0\x2e\x74\x65\x78\x74\0\x2e\x72\x65\x6c\x2e\x42\
\x54\x46\x2e\x65\x78\x74\0\x5f\x5f\x5f\x5f\x75\x70\x72\x6f\x62\x65\x2e\x5f\x5f\
\x5f\x5f\x66\x6d\x74\0\x5f\x5f\x5f\x5f\x75\x72\x65\x74\x70\x72\x6f\x62\x65\x2e\
\x5f\x5f\x5f\x5f\x66\x6d\x74\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x72\
\x61\x6e\x67\x65\x73\0\x2e\x64\x65\x62\x75\x67\x5f\x73\x74\x72\0\x2e\x72\x65\
\x6c\x2e\x64\x65\x62\x75\x67\x5f\x69\x6e\x66\x6f\0\x2e\x6c\x6c\x76\x6d\x5f\x61\
\x64\x64\x72\x73\x69\x67\0\x6c\x69\x63\x65\x6e\x73\x65\0\x2e\x72\x65\x6c\x2e\
\x64\x65\x62\x75\x67\x5f\x6c\x69\x6e\x65\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\
\x67\x5f\x66\x72\x61\x6d\x65\0\x75\x70\x72\x6f\x62\x65\0\x75\x72\x65\x74\x70\
\x72\x6f\x62\x65\0\x2e\x72\x65\x6c\x2e\x64\x65\x62\x75\x67\x5f\x6c\x6f\x63\0\
\x2e\x72\x65\x6c\x75\x70\x72\x6f\x62\x65\x2f\x66\x75\x6e\x63\0\x2e\x72\x65\x6c\
\x75\x72\x65\x74\x70\x72\x6f\x62\x65\x2f\x66\x75\x6e\x63\0\x75\x70\x72\x6f\x62\
\x65\x2e\x62\x70\x66\x2e\x63\0\x2e\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\
\x74\x61\x62\0\x2e\x72\x6f\x64\x61\x74\x61\0\x2e\x72\x65\x6c\x2e\x42\x54\x46\0\
\x4c\x49\x43\x45\x4e\x53\x45\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xff\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x15\x14\0\0\0\0\0\
\0\x28\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\0\
\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd3\0\0\0\x01\0\0\0\x06\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xcf\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xd0\x0e\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x1a\0\0\0\x03\0\0\0\x08\0\0\
\0\0\0\0\0\x10\0\0\0\0\0\0\0\xe3\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x80\0\0\0\0\0\0\0\x38\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\xdf\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\x0e\0\0\0\
\0\0\0\x10\0\0\0\0\0\0\0\x1a\0\0\0\x05\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\
\0\x86\0\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb8\0\0\0\0\0\0\0\x0d\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x0f\x01\0\0\
\x01\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc5\0\0\0\0\0\0\0\x38\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc4\0\0\0\x01\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xfd\0\0\0\0\0\0\0\x66\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xf0\x0e\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x1a\0\0\0\x09\0\0\0\x08\0\0\0\0\
\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x63\x01\0\0\0\0\0\0\x25\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x6c\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\x02\0\0\0\
\0\0\0\xe9\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x68\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x10\x0f\0\0\0\0\0\0\xb0\
\x03\0\0\0\0\0\0\x1a\0\0\0\x0c\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x4f\0\
\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x71\x05\0\0\0\0\0\0\x30\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x4b\0\0\0\x09\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc0\x12\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x1a\0\0\0\
\x0e\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x5d\0\0\0\x01\0\0\0\x30\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xa1\x05\0\0\0\0\0\0\x7a\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x01\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\x1b\x01\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x1b\x07\0\0\0\0\0\0\x49\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x17\x01\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x13\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\x1a\0\0\0\x11\0\0\0\x08\0\0\0\0\0\0\0\x10\
\0\0\0\0\0\0\0\x19\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x64\x0b\0\0\
\0\0\0\0\xb8\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x15\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x30\x13\0\0\0\0\0\0\x80\0\
\0\0\0\0\0\0\x1a\0\0\0\x13\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\xa2\0\0\0\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x0c\0\0\0\0\0\0\x40\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9e\0\0\0\x09\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xb0\x13\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\x1a\0\0\0\x15\
\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x92\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x60\x0c\0\0\0\0\0\0\xeb\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x8e\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xf0\x13\0\0\0\0\0\0\x20\0\0\0\0\0\0\0\x1a\0\0\0\x17\0\0\0\x08\0\0\0\0\0\0\0\
\x10\0\0\0\0\0\0\0\x78\0\0\0\x03\x4c\xff\x6f\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\
\x10\x14\0\0\0\0\0\0\x05\0\0\0\0\0\0\0\x1a\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x07\x01\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\x0d\0\0\
\0\0\0\0\x80\x01\0\0\0\0\0\0\x01\0\0\0\x0d\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\
\0\0\0";

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -1;
}

#endif /* __UPROBE_BPF_SKEL_H__ */
