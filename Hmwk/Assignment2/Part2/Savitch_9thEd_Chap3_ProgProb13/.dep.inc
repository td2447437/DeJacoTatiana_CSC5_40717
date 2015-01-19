# This code depends on make tool being used
DEPFILES=$(wildcard $(addsuffix .d, ${OBJECTFILES}))
DEPFILES=$(wildcard $(addsuffix .d, ${OBJECTFILES}))
ifneq (${DEPFILES},)
ifneq (${DEPFILES},)
include ${DEPFILES}
include ${DEPFILES}
endif
endif
