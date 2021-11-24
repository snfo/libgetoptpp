set(INCDIR ${PROJECT_SOURCE_DIR}/include/getoptpp_internal)
set(SRCDIR ${PROJECT_SOURCE_DIR}/src)
set(SRC ${INCDIR}/arg.hpp
        ${SRCDIR}/option.cpp ${INCDIR}/option.hpp
        ${SRCDIR}/parse.cpp ${INCDIR}/parse.hpp)

add_library(getoptpp STATIC ${SRC})
install(TARGETS getoptpp LIBRARY DESTINATION lib)
