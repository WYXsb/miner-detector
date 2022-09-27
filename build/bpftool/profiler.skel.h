/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED BY BPFTOOL! */
#ifndef __PROFILER_BPF_SKEL_H__
#define __PROFILER_BPF_SKEL_H__

#include <errno.h>
#include <stdlib.h>
#include <bpf/libbpf.h>

struct profiler_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *events;
		struct bpf_map *fentry_readings;
		struct bpf_map *accum_readings;
		struct bpf_map *counts;
		struct bpf_map *rodata;
	} maps;
	struct {
		struct bpf_program *fentry_XXX;
		struct bpf_program *fexit_XXX;
	} progs;
	struct {
		struct bpf_link *fentry_XXX;
		struct bpf_link *fexit_XXX;
	} links;
	struct profiler_bpf__rodata {
		__u32 num_cpu;
		__u32 num_metric;
	} *rodata;

#ifdef __cplusplus
	static inline struct profiler_bpf *open(const struct bpf_object_open_opts *opts = nullptr);
	static inline struct profiler_bpf *open_and_load();
	static inline int load(struct profiler_bpf *skel);
	static inline int attach(struct profiler_bpf *skel);
	static inline void detach(struct profiler_bpf *skel);
	static inline void destroy(struct profiler_bpf *skel);
	static inline const void *elf_bytes(size_t *sz);
#endif /* __cplusplus */
};

static void
profiler_bpf__destroy(struct profiler_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
profiler_bpf__create_skeleton(struct profiler_bpf *obj);

static inline struct profiler_bpf *
profiler_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct profiler_bpf *obj;
	int err;

	obj = (struct profiler_bpf *)calloc(1, sizeof(*obj));
	if (!obj) {
		errno = ENOMEM;
		return NULL;
	}

	err = profiler_bpf__create_skeleton(obj);
	if (err)
		goto err_out;

	err = bpf_object__open_skeleton(obj->skeleton, opts);
	if (err)
		goto err_out;

	return obj;
err_out:
	profiler_bpf__destroy(obj);
	errno = -err;
	return NULL;
}

static inline struct profiler_bpf *
profiler_bpf__open(void)
{
	return profiler_bpf__open_opts(NULL);
}

static inline int
profiler_bpf__load(struct profiler_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct profiler_bpf *
profiler_bpf__open_and_load(void)
{
	struct profiler_bpf *obj;
	int err;

	obj = profiler_bpf__open();
	if (!obj)
		return NULL;
	err = profiler_bpf__load(obj);
	if (err) {
		profiler_bpf__destroy(obj);
		errno = -err;
		return NULL;
	}
	return obj;
}

static inline int
profiler_bpf__attach(struct profiler_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
profiler_bpf__detach(struct profiler_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline const void *profiler_bpf__elf_bytes(size_t *sz);

static inline int
profiler_bpf__create_skeleton(struct profiler_bpf *obj)
{
	struct bpf_object_skeleton *s;
	int err;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)	{
		err = -ENOMEM;
		goto err;
	}

	s->sz = sizeof(*s);
	s->name = "profiler_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 5;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps) {
		err = -ENOMEM;
		goto err;
	}

	s->maps[0].name = "events";
	s->maps[0].map = &obj->maps.events;

	s->maps[1].name = "fentry_readings";
	s->maps[1].map = &obj->maps.fentry_readings;

	s->maps[2].name = "accum_readings";
	s->maps[2].map = &obj->maps.accum_readings;

	s->maps[3].name = "counts";
	s->maps[3].map = &obj->maps.counts;

	s->maps[4].name = "profiler.rodata";
	s->maps[4].map = &obj->maps.rodata;
	s->maps[4].mmaped = (void **)&obj->rodata;

	/* programs */
	s->prog_cnt = 2;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs) {
		err = -ENOMEM;
		goto err;
	}

	s->progs[0].name = "fentry_XXX";
	s->progs[0].prog = &obj->progs.fentry_XXX;
	s->progs[0].link = &obj->links.fentry_XXX;

	s->progs[1].name = "fexit_XXX";
	s->progs[1].prog = &obj->progs.fexit_XXX;
	s->progs[1].link = &obj->links.fexit_XXX;

	s->data = (void *)profiler_bpf__elf_bytes(&s->data_sz);

	obj->skeleton = s;
	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return err;
}

static inline const void *profiler_bpf__elf_bytes(size_t *sz)
{
	*sz = 9120;
	return (const void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\xa0\x1f\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x10\0\
\x01\0\x85\0\0\0\x08\0\0\0\xbf\x06\0\0\0\0\0\0\x18\x07\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x61\x71\0\0\0\0\0\0\x15\x01\x10\0\0\0\0\0\xb7\x08\0\0\0\0\0\0\xbf\xa9\0\0\
\0\0\0\0\x07\x09\0\0\xe0\xff\xff\xff\x63\x8a\xc8\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\
\0\x07\x02\0\0\xc8\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\
\x01\0\0\0\x7b\x09\0\0\0\0\0\0\x15\0\x1e\0\0\0\0\0\x61\x71\0\0\0\0\0\0\x25\x08\
\x03\0\x02\0\0\0\x07\x08\0\0\x01\0\0\0\x07\x09\0\0\x08\0\0\0\x2d\x81\xf3\xff\0\
\0\0\0\x61\x71\0\0\0\0\0\0\x15\x01\x17\0\0\0\0\0\xb7\x07\0\0\0\0\0\0\xbf\xa8\0\
\0\0\0\0\0\x07\x08\0\0\xe0\xff\xff\xff\x18\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x05\
\0\x13\0\0\0\0\0\x79\x81\0\0\0\0\0\0\x79\xa2\xd8\xff\0\0\0\0\x7b\x21\x10\0\0\0\
\0\0\x79\xa2\xd0\xff\0\0\0\0\x7b\x21\x08\0\0\0\0\0\x79\xa2\xc8\xff\0\0\0\0\x7b\
\x21\0\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x11\0\0\0\0\0\0\x61\
\x92\0\0\0\0\0\0\x25\x07\x05\0\x02\0\0\0\x0f\x61\0\0\0\0\0\0\x07\x08\0\0\x08\0\
\0\0\x07\x07\0\0\x01\0\0\0\xbf\x16\0\0\0\0\0\0\x2d\x72\x02\0\0\0\0\0\xb7\0\0\0\
\0\0\0\0\x95\0\0\0\0\0\0\0\xbf\x62\0\0\0\0\0\0\x67\x02\0\0\x20\0\0\0\x77\x02\0\
\0\x20\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xc8\xff\xff\xff\x18\x01\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xb7\x04\0\0\x18\0\0\0\x85\0\0\0\x37\0\0\0\x67\0\0\0\x20\0\0\
\0\x77\0\0\0\x20\0\0\0\x15\0\xe1\xff\0\0\0\0\x05\0\xf1\xff\0\0\0\0\x85\0\0\0\
\x08\0\0\0\xbf\x06\0\0\0\0\0\0\xb7\x08\0\0\0\0\0\0\x63\x8a\x7c\xff\0\0\0\0\x18\
\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x91\0\0\0\0\0\0\x15\x01\x18\0\0\0\0\0\xbf\
\xa7\0\0\0\0\0\0\x07\x07\0\0\x80\xff\xff\xff\x05\0\x05\0\0\0\0\0\x61\x91\0\0\0\
\0\0\0\x25\x08\x13\0\x02\0\0\0\x07\x08\0\0\x01\0\0\0\x07\x07\0\0\x18\0\0\0\x3d\
\x18\x10\0\0\0\0\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x61\x12\0\0\0\0\0\0\x2f\
\x82\0\0\0\0\0\0\x0f\x62\0\0\0\0\0\0\x67\x02\0\0\x20\0\0\0\x77\x02\0\0\x20\0\0\
\0\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x73\0\0\0\0\0\0\xb7\x04\0\0\x18\0\0\
\0\x85\0\0\0\x37\0\0\0\x67\0\0\0\x20\0\0\0\x77\0\0\0\x20\0\0\0\x15\0\xec\xff\0\
\0\0\0\x05\0\x16\0\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\x7c\xff\xff\xff\x18\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\x15\0\x10\0\0\0\0\0\x79\
\x01\0\0\0\0\0\0\x07\x01\0\0\x01\0\0\0\x7b\x10\0\0\0\0\0\0\x18\x06\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x61\x61\0\0\0\0\0\0\x15\x01\x09\0\0\0\0\0\xb7\x07\0\0\0\0\0\0\
\xbf\xa8\0\0\0\0\0\0\x07\x08\0\0\x80\xff\xff\xff\x05\0\x07\0\0\0\0\0\x61\x61\0\
\0\0\0\0\0\x25\x07\x03\0\x02\0\0\0\x07\x08\0\0\x18\0\0\0\x07\x07\0\0\x01\0\0\0\
\x2d\x71\x02\0\0\0\0\0\xb7\0\0\0\0\0\0\0\x95\0\0\0\0\0\0\0\x63\x7a\xfc\xff\0\0\
\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x85\0\0\0\x01\0\0\0\x15\0\xf2\xff\0\0\0\0\x79\x01\0\0\0\0\0\0\x15\
\x01\xf0\xff\0\0\0\0\x79\x81\0\0\0\0\0\0\x79\x02\0\0\0\0\0\0\x1f\x21\0\0\0\0\0\
\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xe0\xff\xff\xff\x7b\x12\0\0\0\0\0\0\x79\x01\
\x08\0\0\0\0\0\x79\x83\x08\0\0\0\0\0\x1f\x13\0\0\0\0\0\0\x7b\x32\x08\0\0\0\0\0\
\x79\x01\x10\0\0\0\0\0\x79\x83\x10\0\0\0\0\0\x1f\x13\0\0\0\0\0\0\x7b\x32\x10\0\
\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\xfc\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\x15\0\xdc\xff\0\0\0\0\xbf\xa1\0\0\0\0\0\0\
\x07\x01\0\0\xe0\xff\xff\xff\x79\x12\0\0\0\0\0\0\x79\x03\0\0\0\0\0\0\x0f\x23\0\
\0\0\0\0\0\x7b\x30\0\0\0\0\0\0\x79\x12\x08\0\0\0\0\0\x79\x03\x08\0\0\0\0\0\x0f\
\x23\0\0\0\0\0\0\x7b\x30\x08\0\0\0\0\0\x79\x11\x10\0\0\0\0\0\x79\x02\x10\0\0\0\
\0\0\x0f\x12\0\0\0\0\0\0\x7b\x20\x10\0\0\0\0\0\x05\0\xcd\xff\0\0\0\0\x01\0\0\0\
\x01\0\0\0\x44\x75\x61\x6c\x20\x42\x53\x44\x2f\x47\x50\x4c\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x9f\xeb\x01\0\x18\0\0\0\0\0\0\0\x4c\x03\0\0\x4c\x03\0\
\0\x4d\x05\0\0\0\0\0\0\0\0\0\x02\x03\0\0\0\x01\0\0\0\0\0\0\x01\x04\0\0\0\x20\0\
\0\x01\0\0\0\0\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x04\0\0\0\x05\0\0\0\0\0\0\
\x01\x04\0\0\0\x20\0\0\0\0\0\0\0\x03\0\0\x04\x18\0\0\0\x19\0\0\0\x01\0\0\0\0\0\
\0\0\x1e\0\0\0\x01\0\0\0\x40\0\0\0\x27\0\0\0\x01\0\0\0\x80\0\0\0\x32\0\0\0\0\0\
\0\x0e\x05\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x08\0\0\0\0\0\0\0\0\0\0\x03\0\0\0\
\0\x02\0\0\0\x04\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\x02\x0a\0\0\0\0\0\0\0\0\0\0\x03\
\0\0\0\0\x02\0\0\0\x04\0\0\0\x18\0\0\0\0\0\0\0\x03\0\0\x04\x18\0\0\0\x19\0\0\0\
\x07\0\0\0\0\0\0\0\x1e\0\0\0\x01\0\0\0\x40\0\0\0\x27\0\0\0\x09\0\0\0\x80\0\0\0\
\x39\0\0\0\0\0\0\x0e\x0b\0\0\0\x01\0\0\0\0\0\0\0\x03\0\0\x04\x18\0\0\0\x19\0\0\
\0\x07\0\0\0\0\0\0\0\x1e\0\0\0\x01\0\0\0\x40\0\0\0\x27\0\0\0\x09\0\0\0\x80\0\0\
\0\x49\0\0\0\0\0\0\x0e\x0d\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x10\0\0\0\0\0\0\0\
\0\0\0\x03\0\0\0\0\x02\0\0\0\x04\0\0\0\x08\0\0\0\0\0\0\0\x03\0\0\x04\x18\0\0\0\
\x19\0\0\0\x07\0\0\0\0\0\0\0\x1e\0\0\0\x01\0\0\0\x40\0\0\0\x27\0\0\0\x0f\0\0\0\
\x80\0\0\0\x58\0\0\0\0\0\0\x0e\x11\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\x02\x14\0\0\0\
\x5f\0\0\0\0\0\0\x01\x08\0\0\0\x40\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\x72\0\0\
\0\x13\0\0\0\x76\0\0\0\x01\0\0\x0c\x15\0\0\0\0\0\0\0\x01\0\0\x0d\x02\0\0\0\x72\
\0\0\0\x13\0\0\0\xff\x01\0\0\x01\0\0\x0c\x17\0\0\0\x7f\x03\0\0\x03\0\0\x04\x18\
\0\0\0\x94\x03\0\0\x1a\0\0\0\0\0\0\0\x9c\x03\0\0\x1a\0\0\0\x40\0\0\0\xa4\x03\0\
\0\x1a\0\0\0\x80\0\0\0\xac\x03\0\0\0\0\0\x08\x14\0\0\0\0\0\0\0\0\0\0\x0a\x1c\0\
\0\0\0\0\0\0\0\0\0\x09\x1d\0\0\0\x04\x05\0\0\0\0\0\x08\x1e\0\0\0\x0a\x05\0\0\0\
\0\0\x01\x04\0\0\0\x20\0\0\0\x17\x05\0\0\0\0\0\x0e\x1b\0\0\0\x01\0\0\0\x1f\x05\
\0\0\0\0\0\x0e\x1b\0\0\0\x01\0\0\0\x2a\x05\0\0\0\0\0\x01\x01\0\0\0\x08\0\0\x01\
\0\0\0\0\0\0\0\x03\0\0\0\0\x21\0\0\0\x04\0\0\0\x0d\0\0\0\x2f\x05\0\0\0\0\0\x0e\
\x22\0\0\0\x01\0\0\0\x37\x05\0\0\x04\0\0\x0f\0\0\0\0\x06\0\0\0\0\0\0\0\x18\0\0\
\0\x0c\0\0\0\0\0\0\0\x18\0\0\0\x0e\0\0\0\0\0\0\0\x18\0\0\0\x12\0\0\0\0\0\0\0\
\x18\0\0\0\x3d\x05\0\0\x02\0\0\x0f\0\0\0\0\x1f\0\0\0\0\0\0\0\x04\0\0\0\x20\0\0\
\0\0\0\0\0\x04\0\0\0\x45\x05\0\0\x01\0\0\x0f\0\0\0\0\x23\0\0\0\0\0\0\0\x0d\0\0\
\0\0\x69\x6e\x74\0\x5f\x5f\x41\x52\x52\x41\x59\x5f\x53\x49\x5a\x45\x5f\x54\x59\
\x50\x45\x5f\x5f\0\x74\x79\x70\x65\0\x6b\x65\x79\x5f\x73\x69\x7a\x65\0\x76\x61\
\x6c\x75\x65\x5f\x73\x69\x7a\x65\0\x65\x76\x65\x6e\x74\x73\0\x66\x65\x6e\x74\
\x72\x79\x5f\x72\x65\x61\x64\x69\x6e\x67\x73\0\x61\x63\x63\x75\x6d\x5f\x72\x65\
\x61\x64\x69\x6e\x67\x73\0\x63\x6f\x75\x6e\x74\x73\0\x75\x6e\x73\x69\x67\x6e\
\x65\x64\x20\x6c\x6f\x6e\x67\x20\x6c\x6f\x6e\x67\0\x63\x74\x78\0\x66\x65\x6e\
\x74\x72\x79\x5f\x58\x58\x58\0\x66\x65\x6e\x74\x72\x79\x2f\x58\x58\x58\0\x2f\
\x68\x6f\x6d\x65\x2f\x77\x79\x78\x2f\x6c\x69\x62\x62\x70\x66\x2d\x62\x6f\x6f\
\x74\x73\x74\x72\x61\x70\x2f\x62\x70\x66\x74\x6f\x6f\x6c\x2f\x73\x72\x63\x2f\
\x73\x6b\x65\x6c\x65\x74\x6f\x6e\x2f\x70\x72\x6f\x66\x69\x6c\x65\x72\x2e\x62\
\x70\x66\x2e\x63\0\x09\x75\x33\x32\x20\x6b\x65\x79\x20\x3d\x20\x62\x70\x66\x5f\
\x67\x65\x74\x5f\x73\x6d\x70\x5f\x70\x72\x6f\x63\x65\x73\x73\x6f\x72\x5f\x69\
\x64\x28\x29\x3b\0\x09\x66\x6f\x72\x20\x28\x69\x20\x3d\x20\x30\x3b\x20\x69\x20\
\x3c\x20\x6e\x75\x6d\x5f\x6d\x65\x74\x72\x69\x63\x20\x26\x26\x20\x69\x20\x3c\
\x20\x4d\x41\x58\x5f\x4e\x55\x4d\x5f\x4d\x41\x54\x52\x49\x43\x53\x3b\x20\x69\
\x2b\x2b\x29\x20\x7b\0\x09\x09\x75\x33\x32\x20\x66\x6c\x61\x67\x20\x3d\x20\x69\
\x3b\0\x09\x09\x70\x74\x72\x73\x5b\x69\x5d\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\
\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x66\x65\x6e\x74\
\x72\x79\x5f\x72\x65\x61\x64\x69\x6e\x67\x73\x2c\x20\x26\x66\x6c\x61\x67\x29\
\x3b\0\x09\x09\x2a\x28\x70\x74\x72\x73\x5b\x69\x5d\x29\x20\x3d\x20\x72\x65\x61\
\x64\x69\x6e\x67\x3b\0\x09\x09\x6b\x65\x79\x20\x2b\x3d\x20\x6e\x75\x6d\x5f\x63\
\x70\x75\x3b\0\x69\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\x4f\x47\x28\x66\x65\x6e\
\x74\x72\x79\x5f\x58\x58\x58\x29\0\x09\x09\x65\x72\x72\x20\x3d\x20\x62\x70\x66\
\x5f\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\x74\x5f\x72\x65\x61\x64\x5f\x76\x61\
\x6c\x75\x65\x28\x26\x65\x76\x65\x6e\x74\x73\x2c\x20\x6b\x65\x79\x2c\x20\x26\
\x72\x65\x61\x64\x69\x6e\x67\x2c\0\x09\x09\x69\x66\x20\x28\x65\x72\x72\x29\0\
\x66\x65\x78\x69\x74\x5f\x58\x58\x58\0\x66\x65\x78\x69\x74\x2f\x58\x58\x58\0\
\x09\x75\x33\x32\x20\x63\x70\x75\x20\x3d\x20\x62\x70\x66\x5f\x67\x65\x74\x5f\
\x73\x6d\x70\x5f\x70\x72\x6f\x63\x65\x73\x73\x6f\x72\x5f\x69\x64\x28\x29\x3b\0\
\x09\x75\x33\x32\x20\x69\x2c\x20\x7a\x65\x72\x6f\x20\x3d\x20\x30\x3b\0\x09\x09\
\x65\x72\x72\x20\x3d\x20\x62\x70\x66\x5f\x70\x65\x72\x66\x5f\x65\x76\x65\x6e\
\x74\x5f\x72\x65\x61\x64\x5f\x76\x61\x6c\x75\x65\x28\x26\x65\x76\x65\x6e\x74\
\x73\x2c\x20\x63\x70\x75\x20\x2b\x20\x69\x20\x2a\x20\x6e\x75\x6d\x5f\x63\x70\
\x75\x2c\0\x09\x63\x6f\x75\x6e\x74\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\
\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x63\x6f\x75\x6e\x74\x73\
\x2c\x20\x26\x7a\x65\x72\x6f\x29\x3b\0\x09\x69\x66\x20\x28\x63\x6f\x75\x6e\x74\
\x29\x20\x7b\0\x09\x09\x2a\x63\x6f\x75\x6e\x74\x20\x2b\x3d\x20\x31\x3b\0\x09\
\x09\x66\x6f\x72\x20\x28\x69\x20\x3d\x20\x30\x3b\x20\x69\x20\x3c\x20\x6e\x75\
\x6d\x5f\x6d\x65\x74\x72\x69\x63\x20\x26\x26\x20\x69\x20\x3c\x20\x4d\x41\x58\
\x5f\x4e\x55\x4d\x5f\x4d\x41\x54\x52\x49\x43\x53\x3b\x20\x69\x2b\x2b\x29\0\x69\
\x6e\x74\x20\x42\x50\x46\x5f\x50\x52\x4f\x47\x28\x66\x65\x78\x69\x74\x5f\x58\
\x58\x58\x29\0\x09\x62\x65\x66\x6f\x72\x65\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\
\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\x6c\x65\x6d\x28\x26\x66\x65\x6e\x74\
\x72\x79\x5f\x72\x65\x61\x64\x69\x6e\x67\x73\x2c\x20\x26\x69\x64\x29\x3b\0\x09\
\x69\x66\x20\x28\x62\x65\x66\x6f\x72\x65\x20\x26\x26\x20\x62\x65\x66\x6f\x72\
\x65\x2d\x3e\x63\x6f\x75\x6e\x74\x65\x72\x29\x20\x7b\0\x62\x70\x66\x5f\x70\x65\
\x72\x66\x5f\x65\x76\x65\x6e\x74\x5f\x76\x61\x6c\x75\x65\0\x63\x6f\x75\x6e\x74\
\x65\x72\0\x65\x6e\x61\x62\x6c\x65\x64\0\x72\x75\x6e\x6e\x69\x6e\x67\0\x5f\x5f\
\x75\x36\x34\0\x30\x3a\x30\0\x09\x09\x64\x69\x66\x66\x2e\x63\x6f\x75\x6e\x74\
\x65\x72\x20\x3d\x20\x61\x66\x74\x65\x72\x2d\x3e\x63\x6f\x75\x6e\x74\x65\x72\
\x20\x2d\x20\x62\x65\x66\x6f\x72\x65\x2d\x3e\x63\x6f\x75\x6e\x74\x65\x72\x3b\0\
\x30\x3a\x31\0\x09\x09\x64\x69\x66\x66\x2e\x65\x6e\x61\x62\x6c\x65\x64\x20\x3d\
\x20\x61\x66\x74\x65\x72\x2d\x3e\x65\x6e\x61\x62\x6c\x65\x64\x20\x2d\x20\x62\
\x65\x66\x6f\x72\x65\x2d\x3e\x65\x6e\x61\x62\x6c\x65\x64\x3b\0\x30\x3a\x32\0\
\x09\x09\x64\x69\x66\x66\x2e\x72\x75\x6e\x6e\x69\x6e\x67\x20\x3d\x20\x61\x66\
\x74\x65\x72\x2d\x3e\x72\x75\x6e\x6e\x69\x6e\x67\x20\x2d\x20\x62\x65\x66\x6f\
\x72\x65\x2d\x3e\x72\x75\x6e\x6e\x69\x6e\x67\x3b\0\x09\x09\x61\x63\x63\x75\x6d\
\x20\x3d\x20\x62\x70\x66\x5f\x6d\x61\x70\x5f\x6c\x6f\x6f\x6b\x75\x70\x5f\x65\
\x6c\x65\x6d\x28\x26\x61\x63\x63\x75\x6d\x5f\x72\x65\x61\x64\x69\x6e\x67\x73\
\x2c\x20\x26\x69\x64\x29\x3b\0\x09\x09\x69\x66\x20\x28\x61\x63\x63\x75\x6d\x29\
\x20\x7b\0\x09\x09\x09\x61\x63\x63\x75\x6d\x2d\x3e\x63\x6f\x75\x6e\x74\x65\x72\
\x20\x2b\x3d\x20\x64\x69\x66\x66\x2e\x63\x6f\x75\x6e\x74\x65\x72\x3b\0\x09\x09\
\x09\x61\x63\x63\x75\x6d\x2d\x3e\x65\x6e\x61\x62\x6c\x65\x64\x20\x2b\x3d\x20\
\x64\x69\x66\x66\x2e\x65\x6e\x61\x62\x6c\x65\x64\x3b\0\x09\x09\x09\x61\x63\x63\
\x75\x6d\x2d\x3e\x72\x75\x6e\x6e\x69\x6e\x67\x20\x2b\x3d\x20\x64\x69\x66\x66\
\x2e\x72\x75\x6e\x6e\x69\x6e\x67\x3b\0\x5f\x5f\x75\x33\x32\0\x75\x6e\x73\x69\
\x67\x6e\x65\x64\x20\x69\x6e\x74\0\x6e\x75\x6d\x5f\x63\x70\x75\0\x6e\x75\x6d\
\x5f\x6d\x65\x74\x72\x69\x63\0\x63\x68\x61\x72\0\x4c\x49\x43\x45\x4e\x53\x45\0\
\x2e\x6d\x61\x70\x73\0\x2e\x72\x6f\x64\x61\x74\x61\0\x6c\x69\x63\x65\x6e\x73\
\x65\0\0\0\0\x9f\xeb\x01\0\x20\0\0\0\0\0\0\0\x24\0\0\0\x24\0\0\0\xf4\x04\0\0\
\x18\x05\0\0\x3c\x01\0\0\x08\0\0\0\x81\0\0\0\x01\0\0\0\0\0\0\0\x16\0\0\0\x09\
\x02\0\0\x01\0\0\0\0\0\0\0\x18\0\0\0\x10\0\0\0\x81\0\0\0\x1a\0\0\0\0\0\0\0\x8c\
\0\0\0\xcb\0\0\0\x0c\xac\0\0\x10\0\0\0\x8c\0\0\0\xf2\0\0\0\x12\xbc\0\0\x28\0\0\
\0\x8c\0\0\0\xf2\0\0\0\x02\xbc\0\0\x48\0\0\0\x8c\0\0\0\x2d\x01\0\0\x07\xc0\0\0\
\x58\0\0\0\x8c\0\0\0\0\0\0\0\0\0\0\0\x60\0\0\0\x8c\0\0\0\x3d\x01\0\0\x0d\xc8\0\
\0\x78\0\0\0\x8c\0\0\0\x3d\x01\0\0\x0b\xc8\0\0\x88\0\0\0\x8c\0\0\0\xf2\0\0\0\
\x12\xbc\0\0\x90\0\0\0\x8c\0\0\0\xf2\0\0\0\x02\xbc\0\0\x98\0\0\0\x8c\0\0\0\0\0\
\0\0\0\0\0\0\xa0\0\0\0\x8c\0\0\0\xf2\0\0\0\x02\xbc\0\0\xb0\0\0\0\x8c\0\0\0\xf2\
\0\0\0\x12\xdc\0\0\xb8\0\0\0\x8c\0\0\0\xf2\0\0\0\x02\xdc\0\0\xd0\0\0\0\x8c\0\0\
\0\0\0\0\0\0\0\0\0\xf0\0\0\0\x8c\0\0\0\x77\x01\0\0\x05\xfc\0\0\xf8\0\0\0\x8c\0\
\0\0\x77\x01\0\0\x10\xfc\0\0\x28\x01\0\0\x8c\0\0\0\x8f\x01\0\0\x0a\0\x01\0\x40\
\x01\0\0\x8c\0\0\0\xf2\0\0\0\x12\xdc\0\0\x48\x01\0\0\x8c\0\0\0\xf2\0\0\0\x02\
\xdc\0\0\x50\x01\0\0\x8c\0\0\0\0\0\0\0\0\0\0\0\x70\x01\0\0\x8c\0\0\0\xf2\0\0\0\
\x02\xdc\0\0\x78\x01\0\0\x8c\0\0\0\xa1\x01\0\0\x05\xa0\0\0\x88\x01\0\0\x8c\0\0\
\0\xba\x01\0\0\x2c\xec\0\0\xa8\x01\0\0\x8c\0\0\0\0\0\0\0\0\0\0\0\xb0\x01\0\0\
\x8c\0\0\0\xba\x01\0\0\x09\xec\0\0\xe0\x01\0\0\x8c\0\0\0\xf4\x01\0\0\x07\xf4\0\
\0\x09\x02\0\0\x34\0\0\0\0\0\0\0\x8c\0\0\0\x13\x02\0\0\x0c\x84\x01\0\x18\0\0\0\
\x8c\0\0\0\x3a\x02\0\0\x09\x88\x01\0\x20\0\0\0\x8c\0\0\0\xf2\0\0\0\x12\x9c\x01\
\0\x38\0\0\0\x8c\0\0\0\xf2\0\0\0\x02\x9c\x01\0\x58\0\0\0\x8c\0\0\0\xf2\0\0\0\
\x12\x9c\x01\0\x60\0\0\0\x8c\0\0\0\xf2\0\0\0\x02\x9c\x01\0\x68\0\0\0\x8c\0\0\0\
\0\0\0\0\0\0\0\0\x70\0\0\0\x8c\0\0\0\xf2\0\0\0\x02\x9c\x01\0\x80\0\0\0\x8c\0\0\
\0\x4c\x02\0\0\x36\xa0\x01\0\x98\0\0\0\x8c\0\0\0\x4c\x02\0\0\x34\xa0\x01\0\xa0\
\0\0\0\x8c\0\0\0\x4c\x02\0\0\x30\xa0\x01\0\xa8\0\0\0\x8c\0\0\0\x4c\x02\0\0\x2c\
\xa0\x01\0\xb8\0\0\0\x8c\0\0\0\x4c\x02\0\0\x09\xa0\x01\0\xf0\0\0\0\x8c\0\0\0\
\xf4\x01\0\0\x07\xa8\x01\0\x08\x01\0\0\x8c\0\0\0\0\0\0\0\0\0\0\0\x10\x01\0\0\
\x8c\0\0\0\x8a\x02\0\0\x0a\xb4\x01\0\x28\x01\0\0\x8c\0\0\0\xb8\x02\0\0\x06\xb8\
\x01\0\x30\x01\0\0\x8c\0\0\0\xc6\x02\0\0\x0a\xbc\x01\0\x48\x01\0\0\x8c\0\0\0\
\xd5\x02\0\0\x13\xc0\x01\0\x60\x01\0\0\x8c\0\0\0\xd5\x02\0\0\x03\xc0\x01\0\x88\
\x01\0\0\x8c\0\0\0\xd5\x02\0\0\x13\xc0\x01\0\x90\x01\0\0\x8c\0\0\0\xd5\x02\0\0\
\x03\xc0\x01\0\x98\x01\0\0\x8c\0\0\0\0\0\0\0\0\0\0\0\xa8\x01\0\0\x8c\0\0\0\xd5\
\x02\0\0\x03\xc0\x01\0\xb0\x01\0\0\x8c\0\0\0\x0f\x03\0\0\x05\x78\x01\0\xd0\x01\
\0\0\x8c\0\0\0\0\0\0\0\0\0\0\0\xd8\x01\0\0\x8c\0\0\0\x27\x03\0\0\x0b\x2c\x01\0\
\xf0\x01\0\0\x8c\0\0\0\x5d\x03\0\0\x0d\x34\x01\0\xf8\x01\0\0\x8c\0\0\0\x5d\x03\
\0\0\x18\x34\x01\0\0\x02\0\0\x8c\0\0\0\x5d\x03\0\0\x06\x34\x01\0\x08\x02\0\0\
\x8c\0\0\0\xb6\x03\0\0\x19\x40\x01\0\x10\x02\0\0\x8c\0\0\0\xb6\x03\0\0\x2b\x40\
\x01\0\x18\x02\0\0\x8c\0\0\0\xb6\x03\0\0\x21\x40\x01\0\x28\x02\0\0\x8c\0\0\0\
\xb6\x03\0\0\x19\x40\x01\0\x30\x02\0\0\x8c\0\0\0\xb6\x03\0\0\x10\x40\x01\0\x38\
\x02\0\0\x8c\0\0\0\xed\x03\0\0\x2b\x44\x01\0\x40\x02\0\0\x8c\0\0\0\xed\x03\0\0\
\x19\x44\x01\0\x48\x02\0\0\x8c\0\0\0\xed\x03\0\0\x21\x44\x01\0\x50\x02\0\0\x8c\
\0\0\0\xed\x03\0\0\x10\x44\x01\0\x58\x02\0\0\x8c\0\0\0\x24\x04\0\0\x2b\x48\x01\
\0\x60\x02\0\0\x8c\0\0\0\x24\x04\0\0\x19\x48\x01\0\x68\x02\0\0\x8c\0\0\0\x24\
\x04\0\0\x21\x48\x01\0\x70\x02\0\0\x8c\0\0\0\x24\x04\0\0\x10\x48\x01\0\x80\x02\
\0\0\x8c\0\0\0\xb6\x03\0\0\x19\x40\x01\0\x88\x02\0\0\x8c\0\0\0\x57\x04\0\0\x0b\
\x50\x01\0\xa0\x02\0\0\x8c\0\0\0\x8c\x04\0\0\x07\x54\x01\0\xb0\x02\0\0\x8c\0\0\
\0\x9b\x04\0\0\x1b\x58\x01\0\xc0\x02\0\0\x8c\0\0\0\x9b\x04\0\0\x13\x58\x01\0\
\xd8\x02\0\0\x8c\0\0\0\xbe\x04\0\0\x1b\x5c\x01\0\xe0\x02\0\0\x8c\0\0\0\xbe\x04\
\0\0\x13\x5c\x01\0\xf8\x02\0\0\x8c\0\0\0\xe1\x04\0\0\x1b\x60\x01\0\0\x03\0\0\
\x8c\0\0\0\xe1\x04\0\0\x13\x60\x01\0\x10\0\0\0\x09\x02\0\0\x13\0\0\0\xf8\x01\0\
\0\x19\0\0\0\xb2\x03\0\0\0\0\0\0\x08\x02\0\0\x19\0\0\0\xb2\x03\0\0\0\0\0\0\x10\
\x02\0\0\x19\0\0\0\xb2\x03\0\0\0\0\0\0\x30\x02\0\0\x19\0\0\0\xb2\x03\0\0\0\0\0\
\0\x38\x02\0\0\x19\0\0\0\xe9\x03\0\0\0\0\0\0\x40\x02\0\0\x19\0\0\0\xe9\x03\0\0\
\0\0\0\0\x50\x02\0\0\x19\0\0\0\xe9\x03\0\0\0\0\0\0\x58\x02\0\0\x19\0\0\0\x20\
\x04\0\0\0\0\0\0\x60\x02\0\0\x19\0\0\0\x20\x04\0\0\0\0\0\0\x70\x02\0\0\x19\0\0\
\0\x20\x04\0\0\0\0\0\0\xb8\x02\0\0\x19\0\0\0\xb2\x03\0\0\0\0\0\0\xc0\x02\0\0\
\x19\0\0\0\xb2\x03\0\0\0\0\0\0\xd0\x02\0\0\x19\0\0\0\xb2\x03\0\0\0\0\0\0\xd8\
\x02\0\0\x19\0\0\0\xe9\x03\0\0\0\0\0\0\xe0\x02\0\0\x19\0\0\0\xe9\x03\0\0\0\0\0\
\0\xf0\x02\0\0\x19\0\0\0\xe9\x03\0\0\0\0\0\0\xf8\x02\0\0\x19\0\0\0\x20\x04\0\0\
\0\0\0\0\0\x03\0\0\x19\0\0\0\x20\x04\0\0\0\0\0\0\x10\x03\0\0\x19\0\0\0\x20\x04\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x03\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe7\0\0\0\0\0\x03\0\xb0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x04\x01\0\0\0\0\x03\0\x48\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x13\x01\0\0\
\0\0\x03\0\x78\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd9\0\0\0\0\0\x03\0\x88\x01\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\xcb\0\0\0\0\0\x03\0\xf0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x03\0\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe0\0\0\0\0\0\x05\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xee\0\0\0\0\0\x05\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\xfd\0\0\0\0\0\x05\0\x58\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf5\0\0\0\0\0\x05\0\
\xb0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd2\0\0\0\0\0\x05\0\xc0\x01\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\x0b\x01\0\0\0\0\x05\0\x88\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x88\0\
\0\0\x12\0\x03\0\0\0\0\0\0\0\0\0\xf0\x01\0\0\0\0\0\0\x65\0\0\0\x11\0\x07\0\x04\
\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x30\0\0\0\x11\0\x09\0\x18\0\0\0\0\0\0\0\x18\0\
\0\0\0\0\0\0\x01\0\0\0\x11\0\x07\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\x23\0\0\0\
\x11\0\x09\0\0\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\x93\0\0\0\x12\0\x05\0\0\0\0\0\0\
\0\0\0\x20\x03\0\0\0\0\0\0\x1c\0\0\0\x11\0\x09\0\x48\0\0\0\0\0\0\0\x18\0\0\0\0\
\0\0\0\x40\0\0\0\x11\0\x09\0\x30\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0\xc3\0\0\0\x11\
\0\x08\0\0\0\0\0\0\0\0\0\x0d\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\
\0\x60\0\0\0\0\0\0\0\x01\0\0\0\x10\0\0\0\xd8\0\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\0\
\x28\x01\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\xb0\x01\0\0\0\0\0\0\x01\0\0\0\x12\0\0\
\0\x20\0\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\0\x80\0\0\0\0\0\0\0\x01\0\0\0\x11\0\0\0\
\xb8\0\0\0\0\0\0\0\x01\0\0\0\x12\0\0\0\x10\x01\0\0\0\0\0\0\x01\0\0\0\x14\0\0\0\
\x48\x01\0\0\0\0\0\0\x01\0\0\0\x0f\0\0\0\xd8\x01\0\0\0\0\0\0\x01\0\0\0\x10\0\0\
\0\x88\x02\0\0\0\0\0\0\x01\0\0\0\x15\0\0\0\xfc\x02\0\0\0\0\0\0\x04\0\0\0\x12\0\
\0\0\x08\x03\0\0\0\0\0\0\x04\0\0\0\x10\0\0\0\x14\x03\0\0\0\0\0\0\x04\0\0\0\x15\
\0\0\0\x20\x03\0\0\0\0\0\0\x04\0\0\0\x14\0\0\0\x38\x03\0\0\0\0\0\0\x03\0\0\0\
\x11\0\0\0\x44\x03\0\0\0\0\0\0\x03\0\0\0\x0f\0\0\0\x5c\x03\0\0\0\0\0\0\x04\0\0\
\0\x16\0\0\0\x2c\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x3c\0\0\0\0\0\0\0\x04\0\0\0\
\x07\0\0\0\x50\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x60\0\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\x70\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x80\0\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\x90\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xa0\0\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\xb0\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xc0\0\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\xd0\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xe0\0\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\xf0\0\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\0\x01\0\0\0\0\0\0\x04\0\0\0\
\x01\0\0\0\x10\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x20\x01\0\0\0\0\0\0\x04\0\0\
\0\x01\0\0\0\x30\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x40\x01\0\0\0\0\0\0\x04\0\
\0\0\x01\0\0\0\x50\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x60\x01\0\0\0\0\0\0\x04\
\0\0\0\x01\0\0\0\x70\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\x80\x01\0\0\0\0\0\0\
\x04\0\0\0\x01\0\0\0\x90\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xa0\x01\0\0\0\0\0\
\0\x04\0\0\0\x01\0\0\0\xb0\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xc0\x01\0\0\0\0\
\0\0\x04\0\0\0\x01\0\0\0\xd0\x01\0\0\0\0\0\0\x04\0\0\0\x01\0\0\0\xe0\x01\0\0\0\
\0\0\0\x04\0\0\0\x01\0\0\0\xf8\x01\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x08\x02\0\0\
\0\0\0\0\x04\0\0\0\x07\0\0\0\x18\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x28\x02\0\
\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x38\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x48\x02\
\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x58\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x68\
\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x78\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\
\x88\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x98\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\
\0\xa8\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xb8\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\
\0\0\xc8\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xd8\x02\0\0\0\0\0\0\x04\0\0\0\x07\
\0\0\0\xe8\x02\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xf8\x02\0\0\0\0\0\0\x04\0\0\0\
\x07\0\0\0\x08\x03\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x18\x03\0\0\0\0\0\0\x04\0\0\
\0\x07\0\0\0\x28\x03\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x38\x03\0\0\0\0\0\0\x04\0\
\0\0\x07\0\0\0\x48\x03\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x58\x03\0\0\0\0\0\0\x04\
\0\0\0\x07\0\0\0\x68\x03\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x78\x03\0\0\0\0\0\0\
\x04\0\0\0\x07\0\0\0\x88\x03\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x98\x03\0\0\0\0\0\
\0\x04\0\0\0\x07\0\0\0\xa8\x03\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xb8\x03\0\0\0\0\
\0\0\x04\0\0\0\x07\0\0\0\xc8\x03\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xd8\x03\0\0\0\
\0\0\0\x04\0\0\0\x07\0\0\0\xe8\x03\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xf8\x03\0\0\
\0\0\0\0\x04\0\0\0\x07\0\0\0\x08\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x18\x04\0\
\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x28\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x38\x04\
\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x48\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x58\
\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x68\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\
\x78\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x88\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\
\0\x98\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xa8\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\
\0\0\xb8\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xc8\x04\0\0\0\0\0\0\x04\0\0\0\x07\
\0\0\0\xd8\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xe8\x04\0\0\0\0\0\0\x04\0\0\0\
\x07\0\0\0\xf8\x04\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x08\x05\0\0\0\0\0\0\x04\0\0\
\0\x07\0\0\0\x18\x05\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x28\x05\0\0\0\0\0\0\x04\0\
\0\0\x07\0\0\0\x44\x05\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x54\x05\0\0\0\0\0\0\x04\
\0\0\0\x07\0\0\0\x64\x05\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x74\x05\0\0\0\0\0\0\
\x04\0\0\0\x07\0\0\0\x84\x05\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x94\x05\0\0\0\0\0\
\0\x04\0\0\0\x07\0\0\0\xa4\x05\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xb4\x05\0\0\0\0\
\0\0\x04\0\0\0\x07\0\0\0\xc4\x05\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xd4\x05\0\0\0\
\0\0\0\x04\0\0\0\x07\0\0\0\xe4\x05\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\xf4\x05\0\0\
\0\0\0\0\x04\0\0\0\x07\0\0\0\x04\x06\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x14\x06\0\
\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x24\x06\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x34\x06\
\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x44\x06\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x54\
\x06\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\x64\x06\0\0\0\0\0\0\x04\0\0\0\x07\0\0\0\
\x18\x1d\x1b\x19\x20\x1c\x1a\x1f\x1e\0\x6e\x75\x6d\x5f\x63\x70\x75\0\x2e\x74\
\x65\x78\x74\0\x2e\x72\x65\x6c\x2e\x42\x54\x46\x2e\x65\x78\x74\0\x63\x6f\x75\
\x6e\x74\x73\0\x65\x76\x65\x6e\x74\x73\0\x2e\x6d\x61\x70\x73\0\x66\x65\x6e\x74\
\x72\x79\x5f\x72\x65\x61\x64\x69\x6e\x67\x73\0\x61\x63\x63\x75\x6d\x5f\x72\x65\
\x61\x64\x69\x6e\x67\x73\0\x2e\x6c\x6c\x76\x6d\x5f\x61\x64\x64\x72\x73\x69\x67\
\0\x6c\x69\x63\x65\x6e\x73\x65\0\x6e\x75\x6d\x5f\x6d\x65\x74\x72\x69\x63\0\x2e\
\x73\x74\x72\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x2e\x72\x6f\x64\x61\
\x74\x61\0\x66\x65\x6e\x74\x72\x79\x5f\x58\x58\x58\0\x66\x65\x78\x69\x74\x5f\
\x58\x58\x58\0\x2e\x72\x65\x6c\x66\x65\x6e\x74\x72\x79\x2f\x58\x58\x58\0\x2e\
\x72\x65\x6c\x66\x65\x78\x69\x74\x2f\x58\x58\x58\0\x2e\x72\x65\x6c\x2e\x42\x54\
\x46\0\x4c\x49\x43\x45\x4e\x53\x45\0\x4c\x42\x42\x30\x5f\x39\0\x4c\x42\x42\x31\
\x5f\x38\0\x4c\x42\x42\x30\x5f\x37\0\x4c\x42\x42\x31\x5f\x35\0\x4c\x42\x42\x30\
\x5f\x35\0\x4c\x42\x42\x31\x5f\x34\0\x4c\x42\x42\x31\x5f\x31\x34\0\x4c\x42\x42\
\x31\x5f\x32\0\x4c\x42\x42\x30\x5f\x32\0\x4c\x42\x42\x31\x5f\x31\x32\0\x4c\x42\
\x42\x30\x5f\x31\x31\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x70\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x81\x1e\0\0\0\0\0\0\x1b\
\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x09\0\0\0\
\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa1\0\0\0\x01\0\0\0\x06\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\0\0\xf0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9d\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x18\x17\0\0\0\0\0\0\x50\0\0\0\0\0\0\0\x0f\0\0\0\x03\0\0\0\x08\0\0\
\0\0\0\0\0\x10\0\0\0\0\0\0\0\xb0\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x30\x02\0\0\0\0\0\0\x20\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xac\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\x17\
\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\x0f\0\0\0\x05\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\
\0\0\0\0\x80\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x50\x05\0\0\0\0\
\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x5d\0\
\0\0\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\x05\0\0\0\0\0\0\x0d\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x2a\0\0\0\x01\0\0\0\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x68\x05\0\0\0\0\0\0\x60\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbe\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xc8\x05\0\0\0\0\0\0\xb1\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xba\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\xd8\x17\0\0\0\0\0\0\x70\0\0\0\0\0\0\0\x0f\0\0\0\x0a\0\0\0\x08\0\0\0\0\0\
\0\0\x10\0\0\0\0\0\0\0\x13\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7c\
\x0e\0\0\0\0\0\0\x74\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\x0f\0\0\0\x09\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x18\0\0\0\0\
\0\0\x30\x06\0\0\0\0\0\0\x0f\0\0\0\x0c\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\
\0\x4f\0\0\0\x03\x4c\xff\x6f\0\0\0\x80\0\0\0\0\0\0\0\0\0\0\0\0\x78\x1e\0\0\0\0\
\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\0\
\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf0\x14\0\0\0\0\0\0\x28\x02\0\0\
\0\0\0\0\x01\0\0\0\x0e\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\0\0\0";
}

#ifdef __cplusplus
struct profiler_bpf *profiler_bpf::open(const struct bpf_object_open_opts *opts) { return profiler_bpf__open_opts(opts); }
struct profiler_bpf *profiler_bpf::open_and_load() { return profiler_bpf__open_and_load(); }
int profiler_bpf::load(struct profiler_bpf *skel) { return profiler_bpf__load(skel); }
int profiler_bpf::attach(struct profiler_bpf *skel) { return profiler_bpf__attach(skel); }
void profiler_bpf::detach(struct profiler_bpf *skel) { profiler_bpf__detach(skel); }
void profiler_bpf::destroy(struct profiler_bpf *skel) { profiler_bpf__destroy(skel); }
const void *profiler_bpf::elf_bytes(size_t *sz) { return profiler_bpf__elf_bytes(sz); }
#endif /* __cplusplus */

__attribute__((unused)) static void
profiler_bpf__assert(struct profiler_bpf *s __attribute__((unused)))
{
#ifdef __cplusplus
#define _Static_assert static_assert
#endif
	_Static_assert(sizeof(s->rodata->num_cpu) == 4, "unexpected size of 'num_cpu'");
	_Static_assert(sizeof(s->rodata->num_metric) == 4, "unexpected size of 'num_metric'");
#ifdef __cplusplus
#undef _Static_assert
#endif
}

#endif /* __PROFILER_BPF_SKEL_H__ */
