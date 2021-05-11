# MIT License

add_executable(pong pong.cpp game_scene.cpp)
target_link_libraries(pong ${FROG_TARGET})
configure_file(ball.png ${CMAKE_BINARY_DIR}/bin/ball.png COPYONLY)
