cmake_minimum_required (VERSION 3.8)

project (ProgPractice)

# ��������� �������� ������ ��������������
if(MSVC) # ���������� MSVC /W3
    if(CMAKE_C_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    else()
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
    endif()
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options(/experimental:external /external:anglebrackets /external:W0)
 

elseif(CMAKE_COMPILER_IS_GNUCC) # ���������� GCC
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wconversion -Wextra -Wpedantic")
endif()


add_subdirectory(practice1)
add_subdirectory(practice2)
