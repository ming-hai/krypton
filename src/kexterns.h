/*
 * Copyright (c) 2014-2016 Cesanta Software Limited
 * All rights reserved
 */

#ifndef CS_KRYPTON_SRC_KEXTERNS_H_
#define CS_KRYPTON_SRC_KEXTERNS_H_

#if !defined(KR_EXT_IO) && (defined(_POSIX_VERSION) || defined(WIN32))
#define KR_EXT_IO 0
#endif

#if KR_EXT_IO
extern ssize_t kr_send(int fd, const void *buf, size_t len);
extern ssize_t kr_recv(int fd, void *buf, size_t len);
#endif
#ifdef KR_EXT_RANDOM
extern int kr_get_random(uint8_t *out, size_t len);
#endif
#ifdef KR_EXT_MD5
extern void kr_hash_md5_v(size_t num_msgs, const uint8_t *msgs[],
                          const size_t *msg_lens, uint8_t *digest);
#endif
#ifdef KR_EXT_SHA1
extern void kr_hash_sha1_v(size_t num_msgs, const uint8_t *msgs[],
                           const size_t *msg_lens, uint8_t *digest);
#endif
#ifdef KR_EXT_SHA256
extern void kr_hash_sha256_v(size_t num_msgs, const uint8_t *msgs[],
                             const size_t *msg_lens, uint8_t *digest);
#endif
#ifndef KR_ENABLE_FILESYSTEM
#define KR_ENABLE_FILESYSTEM 1
#endif

/* Some defaults. */

#if !defined(KR_EXT_RANDOM)
#if defined(__unix__)
#define KR_RANDOM_SOURCE_FILE "/dev/urandom"
#else
#define KR_USE_RAND
#endif
#endif

#endif /* CS_KRYPTON_SRC_KEXTERNS_H_ */
