# $(call make-depend,source-file,object-file,depend-file)
define make-depend
  $(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -M $1 |	\
	$(SED) 's,\($(notdir $2)\) *:,$2 $3: ,' > $3.tmp
	# Append empty rules
	$(SED)  -e 's/#.*//'		\
		-e 's/^[^:]*: *//'	\
		-e 's/ *\\$$//'		\
		-e '/^$$/ d'		\
		-e 's/$$/ :/'		\
		< $3.tmp >> $3.tmp
  $(MV) $3.tmp $3
endef

# $(call to-dep-file,suffix,file-list)
# path/source.o -> path/.source.d
define to-dep-file
	$(foreach f,$(subst $1,.d,$2),$(dir $(f)).$(notdir $(f)))
endef
