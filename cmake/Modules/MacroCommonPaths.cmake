macro(MacroCommonPaths NAME DIR_NAME)
  IF(DEFINED ENV{${NAME}_ROOT} OR DEFINED ENV{${NAME}_DIR})
    set(COMMON_INCLUDE_PATHS_${NAME}
      /opt/scrimmage/include/JSBSim
      $ENV{${NAME}_DIR}/src
      $ENV{${NAME}_DIR}/include
      $ENV{${NAME}_DIR}
      $ENV{${NAME}_ROOT}/src
      $ENV{${NAME}_ROOT}/include
      $ENV{${NAME}_ROOT}
      )
  ELSE()
    set(COMMON_INCLUDE_PATHS_${NAME}
      /opt/scrimmage/include
      ~/Library/Frameworks
      /Library/Frameworks
      /usr/local/include
      /usr/local/include/${DIR_NAME}
      /usr/include
      /usr/include/${DIR_NAME}
      /sw/include # Fink
      /opt/local/include # DarwinPorts
      /opt/csw/include # Blastwave
      /opt/include
      [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\\Manager\\Environment;${NAME}_DIR]/include
      [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\\Manager\\Environment;${NAME}_ROOT]/include
      /usr/freeware/include
      )
  ENDIF()

  IF(DEFINED ENV{${NAME}_ROOT} OR DEFINED ENV{${NAME}_DIR})
    set(COMMON_LIBRARY_PATHS_${NAME}
      $ENV{${NAME}_DIR}/build/src
      $ENV{${NAME}_DIR}/lib
      $ENV{${NAME}_DIR}
      $ENV{${NAME}_ROOT}/build/src
      $ENV{${NAME}_ROOT}/lib
      $ENV{${NAME}_ROOT}
      )
  ELSE()
    set(COMMON_LIBRARY_PATHS_${NAME}
      /opt/scrimmage/lib
      ~/Library/Frameworks
      /Library/Frameworks
      /usr/local/lib
      /usr/lib
      /sw/lib
      /opt/local/lib
      /opt/csw/lib
      /opt/lib
      [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\\Manager\\Environment;${NAME}_DIR]/lib
      [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\\Manager\\Environment;${NAME}_ROOT]/lib
      /usr/freeware/lib64
      )
  ENDIF()

  set(COMMON_DATA_PATHS_${NAME}
    $ENV{${NAME}_DIR}/share
    $ENV{${NAME}_DIR}
    $ENV{${NAME}_ROOT}/share
    $ENV{${NAME}_ROOT}
    /opt/scrimmage/etc
    ~/Library/Frameworks
    /Library/Frameworks
    /usr/local/share
    /usr/share
    /sw/share
    /opt/local/share
    /opt/csw/share
    /opt/share
    [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\\Manager\\Environment;${NAME}_DIR]/share
    [HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session\\Manager\\Environment;${NAME}_ROOT]/share
    /usr/freeware/share64
    )

endmacro(MacroCommonPaths)

# vim:ts=4:sw=4:expandtab
