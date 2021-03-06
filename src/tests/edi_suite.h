#ifndef _EDI_SUITE_H
#define _EDI_SUITE_H

#include <check.h>

#include <Edi.h>

void edi_test_basic(TCase *tc);
void edi_test_console(TCase *tc);
void edi_test_path(TCase *tc);
void edi_test_content_provider(TCase *tc);

#endif /* _EDI_SUITE_H */
