/*
 * Copyright (c) 2019 Arduino SA. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef DES_H
#define DES_H

#include <bearssl/bearssl_block.h>

#include "Encryption.h"

#define DES_BLOCK_SIZE 8
#define DES_DIGEST_SIZE 8

class DESClass: public EncryptionClass {

public:
  DESClass();
  virtual ~DESClass();

protected:
  virtual int runEncryption(uint8_t *key, size_t size, uint8_t *input, size_t block_size, uint8_t *iv);
  virtual int runDecryption(uint8_t *key, size_t size, uint8_t *input, size_t block_size, uint8_t *iv);

private:
  br_des_ct_cbcenc_keys cbcenc_ctx;
  br_des_ct_cbcdec_keys cbcdec_ctx;
};

extern DESClass DES;

#endif
