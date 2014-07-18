/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

#pragma once

/***
  This file is part of systemd.

  Copyright 2014 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#include "in-addr-util.h"

typedef struct DnsServer DnsServer;
typedef enum DnsServerSource DnsServerSource;

#include "resolved.h"
#include "resolved-link.h"
#include "resolved-dns-server.h"

enum DnsServerSource {
        DNS_SERVER_SYSTEM,
        DNS_SERVER_LINK,
        DNS_SERVER_DHCP,
        _DNS_SERVER_SOURCE_MAX
};

struct DnsServer {
        Manager *manager;
        DnsServerSource source;

        Link *link;

        unsigned char family;
        union in_addr_union address;

        bool marked:1;

        LIST_FIELDS(DnsServer, servers);
};

int dns_server_new(
                Manager *m,
                DnsServer **s,
                DnsServerSource source,
                Link *l,
                unsigned char family,
                const union in_addr_union *address);

DnsServer* dns_server_free(DnsServer *s);