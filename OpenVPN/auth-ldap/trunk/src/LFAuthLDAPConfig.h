/*
 * LFAuthLDAPConfig.h
 * Simple Configuration
 *
 * Copyright (c) 2005 Landon Fuller <landonf@threerings.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of Landon Fuller nor the names of any contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef LFAUTHLDAPCONFIG_H
#define LFAUTHLDAPCONFIG_H

#include "TRObject.h"
#include "TRArray.h"
#include "TRConfig.h"

@interface LFAuthLDAPConfig : TRObject <TRConfigDelegate> {
	/* LDAP Settings */
	char *url;
	int tlsEnabled;
	int timeout;
	char *tlsCACertFile;
	char *tlsCACertDir;
	char *tlsCertFile;
	char *tlsKeyFile;
	char *tlsCipherSuite;

	/* Parser State */
	TRConfig *_configDriver;
	TRArray *_sectionStack;
}

- (id) initWithConfigFile: (const char *) fileName;
- (void) setKey: (TRConfigToken *) key value: (TRConfigToken *) value;
- (void) startSection: (TRConfigToken *) sectionType sectionName: (TRConfigToken *) name;
- (void) endSection: (TRConfigToken *) sectionEnd;

- (const char *) url;
- (void) setURL: (const char *) newURL;

- (int) timeout;
- (void) setTimeout: (int) newTimeout;

- (int) tlsEnabled;
- (void) setTLSEnabled: (int) newTLSSetting;

- (const char *) tlsCACertFile;
- (void) setTLSCACertFile: (const char *) fileName;

- (const char *) tlsCACertDir;
- (void) setTLSCACertDir: (const char *) directoryName;

- (const char *) tlsCertFile;
- (void) setTLSCertFile: (const char *) newFilename;

- (const char *) tlsKeyFile;
- (void) setTLSKeyFile: (const char *) fileName;

- (const char *) tlsCipherSuite;
- (void) setTLSCipherSuite: (const char *) cipherSuite;

@end

#endif /* LFAUTHLDAPCONFIG_H */
