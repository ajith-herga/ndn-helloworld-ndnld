#include <stdlib.h>
#include <sys/types.h>
#include "inet_adjust.h"
#include <stdio.h>
#include <ctype.h>
struct ether_addr
{
      u_int8_t ether_addr_octet[6];
} __attribute__ ((__packed__));

struct ether_addr *
ether_aton (const char *asc)
{
  static struct ether_addr addr;
  size_t cnt;

  for (cnt = 0; cnt < 6; ++cnt)
    {
      unsigned int number;
      char ch;

      ch = tolower (*asc++);
      if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f'))
	return NULL;
      number = isdigit (ch) ? (ch - '0') : (ch - 'a' + 10);

      ch = tolower (*asc);
      if ((cnt < 5 && ch != ':') || (cnt == 5 && ch != '\0' && !isspace (ch)))
	{
	  ++asc;
	  if ((ch < '0' || ch > '9') && (ch < 'a' || ch > 'f'))
	    return NULL;
	  number <<= 4;
	  number += isdigit (ch) ? (ch - '0') : (ch - 'a' + 10);

	  ch = *asc;
	  if (cnt < 5 && ch != ':')
	    return NULL;
	}

      /* Store result.  */
      addr.ether_addr_octet[cnt] = (unsigned char) number;

      /* Skip ':'.  */
      ++asc;
    }

  return &addr;
}

char *
ether_ntoa (const struct ether_addr *addr)
{
  static char buf[18];
  sprintf (buf, "%x:%x:%x:%x:%x:%x",
       addr->ether_addr_octet[0], addr->ether_addr_octet[1],
       addr->ether_addr_octet[2], addr->ether_addr_octet[3],
       addr->ether_addr_octet[4], addr->ether_addr_octet[5]);
  return buf;
}
