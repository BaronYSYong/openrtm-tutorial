set(hdrs SimpleServiceProvider.h
    PARENT_SCOPE
    SimpleServiceSVC_impl.h
    )

install(FILES ${hdrs} DESTINATION ${INC_INSTALL_DIR}/${PROJECT_NAME_LOWER}
    COMPONENT library)

