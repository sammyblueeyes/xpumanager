cmake_minimum_required(VERSION 3.14.0)
project(win_dll)

find_package(Doxygen)

if(NOT DOXYGEN_FOUND)
  message(FATAL_ERROR "Doxygen not found, please install first")
endif()

set(XPUM_DOC_DOXYFILE ${CMAKE_CURRENT_LIST_DIR}/../Doxyfile)

set(DOXYREST_FOLDER ${CMAKE_CURRENT_LIST_DIR}/../doxyrest)

if((${distro} MATCHES "CentOS") OR (${distro} MATCHES "openSUSE"))
  set(DOXYREST_PATH ${DOXYREST_FOLDER}/bin/doxyrest-rh)
else()
  set(DOXYREST_PATH ${DOXYREST_FOLDER}/bin/doxyrest)
endif()

set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_GENERATE_HTML NO)
set(DOXYGEN_GENERATE_LATEX NO)
set(DOXYGEN_GENERATE_XML YES)
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doxygen-output")

doxygen_add_docs(
  WIN_DLL_XML
  ${CMAKE_CURRENT_LIST_DIR}/../../windows/winxpum/core/include/xpum_api.h
  ${CMAKE_CURRENT_LIST_DIR}/../../windows/winxpum/core/include/xpum_structs.h
)

set(LIB_CORE_API_DOC_TITLE "Core Library API")

add_custom_target(
  WIN_DLL_RST
  COMMAND ${DOXYREST_PATH}
            -c ${DOXYREST_FOLDER}/share/doxyrest/frame/doxyrest-config.lua
            -F ${DOXYREST_FOLDER}/share/doxyrest/frame/cfamily 
            -F ${DOXYREST_FOLDER}/share/doxyrest/frame/common 
            -o ${CMAKE_CURRENT_BINARY_DIR}/rst/index.rst 
            -D SORT_GROUPS_BY="originalIdx"
            -D INDEX_TITLE=${LIB_CORE_API_DOC_TITLE}
            -D DOXID_PREFIX="win-doxid"
            ${CMAKE_CURRENT_BINARY_DIR}/doxygen-output/xml/index.xml
  DEPENDS WIN_DLL_XML)

add_custom_target(win_dll ALL DEPENDS WIN_DLL_RST)
