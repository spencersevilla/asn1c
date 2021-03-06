/*-
 * Copyright (c) 2003, 2005, 2006 Lev Walkin <vlm@lionet.info>.
 * All rights reserved.
 * Redistribution and modifications are permitted subject to BSD license.
 */
#include <asn_internal.h>
#include <ENUMERATED.h>
#include <NativeEnumerated.h>
#include <asn_codecs_prim.h>	/* Encoder and decoder of a primitive type */

/*
 * ENUMERATED basic type description.
 */
static ber_tlv_tag_t asn_DEF_ENUMERATED_tags[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_ENUMERATED = {
	"ENUMERATED",
	"ENUMERATED",
	ASN__PRIMITIVE_TYPE_free,
	INTEGER_print,			/* Implemented in terms of INTEGER */
	asn_generic_no_constraint,
	ber_decode_primitive,
	INTEGER_encode_der,		/* Implemented in terms of INTEGER */
	INTEGER_decode_xer,	/* This is temporary! */
	INTEGER_encode_xer,
	ENUMERATED_decode_uper,	/* Unaligned PER decoder */
	ENUMERATED_encode_uper,	/* Unaligned PER encoder */
	ENUMERATED_decode_aper,	/* Aligned PER decoder */
  ENUMERATED_encode_aper, /* Aligned PER encoder */
  ENUMERATED_compare,
	0, /* Use generic outmost tag fetcher */
	asn_DEF_ENUMERATED_tags,
	sizeof(asn_DEF_ENUMERATED_tags) / sizeof(asn_DEF_ENUMERATED_tags[0]),
	asn_DEF_ENUMERATED_tags,	/* Same as above */
	sizeof(asn_DEF_ENUMERATED_tags) / sizeof(asn_DEF_ENUMERATED_tags[0]),
	0,	/* No PER visible constraints */
	0, 0,	/* No members */
	0	/* No specifics */
};

asn_dec_rval_t
ENUMERATED_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
	asn_per_constraints_t *constraints, void **sptr, asn_per_data_t *pd) {
	asn_dec_rval_t rval;
	ENUMERATED_t *st = (ENUMERATED_t *)*sptr;
	long value;
	void *vptr = &value;

	if(!st) {
		st = (ENUMERATED_t *)(*sptr = CALLOC(1, sizeof(*st)));
		if(!st) _ASN_DECODE_FAILED;
	}

	rval = NativeEnumerated_decode_uper(opt_codec_ctx, td, constraints,
			(void **)&vptr, pd);
	if(rval.code == RC_OK)
		if(asn_long2INTEGER(st, value))
			rval.code = RC_FAIL;
	return rval;
}

asn_dec_rval_t
ENUMERATED_decode_aper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
	asn_per_constraints_t *constraints, void **sptr, asn_per_data_t *pd) {
	asn_dec_rval_t rval;
	ENUMERATED_t *st = (ENUMERATED_t *)*sptr;
	long value;
	void *vptr = &value;

	if(!st) {
		st = (ENUMERATED_t *)(*sptr = CALLOC(1, sizeof(*st)));
		if(!st) _ASN_DECODE_FAILED;
	}

	rval = NativeEnumerated_decode_aper(opt_codec_ctx, td, constraints,
			(void **)&vptr, pd);
	if(rval.code == RC_OK)
		if(asn_long2INTEGER(st, value))
			rval.code = RC_FAIL;
	return rval;
}

asn_enc_rval_t
ENUMERATED_encode_uper(asn_TYPE_descriptor_t *td,
	asn_per_constraints_t *constraints, void *sptr, asn_per_outp_t *po) {
	ENUMERATED_t *st = (ENUMERATED_t *)sptr;
	long value;

	if(asn_INTEGER2long(st, &value))
		_ASN_ENCODE_FAILED;

	return NativeEnumerated_encode_uper(td, constraints, &value, po);
}

asn_enc_rval_t
ENUMERATED_encode_aper(asn_TYPE_descriptor_t *td,
	asn_per_constraints_t *constraints, void *sptr, asn_per_outp_t *po) {
	ENUMERATED_t *st = (ENUMERATED_t *)sptr;
	long value;
	
	if(asn_INTEGER2long(st, &value))
		_ASN_ENCODE_FAILED;
	
	return NativeEnumerated_encode_aper(td, constraints, &value, po);
}

asn_comp_rval_t *
ENUMERATED_compare(asn_TYPE_descriptor_t *td1, const void *sptr1,
                   asn_TYPE_descriptor_t *td2, const void *sptr2) {
  const ENUMERATED_t *st1 = (const ENUMERATED_t *)sptr1;
  const ENUMERATED_t *st2 = (const ENUMERATED_t *)sptr2;
  asn_comp_rval_t *res = NULL;

  COMPARE_CHECK_ARGS(td1, td2, sptr1, sptr2, res)

  if (*st1 == *st2) return NULL;
  res = calloc(1, sizeof(asn_comp_rval_t));
  res->name = td1->name;
  res->structure1 = sptr1;
  res->structure2 = sptr2;
  res->err_code = COMPARE_ERR_CODE_NO_MATCH;
  return res;
}

