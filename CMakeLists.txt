# Yêu cầu phiên bản CMake tối thiểu để chạy
cmake_minimum_required(VERSION 3.10)

# Đặt tên cho dự án
project(TaiXiuSimulation)

# Sử dụng chuẩn C++14 (hoặc C++17) để hỗ trợ các tính năng hiện đại
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Tự động quét và gom tất cả các file mã nguồn (.cpp) nằm trong thư mục src/ vào một biến tên là SOURCES
file(GLOB SOURCES "src/*.cpp")

# Tạo ra một ứng dụng thực thi (file chạy) tên là "TaiXiuSim" từ các file SOURCES trên
add_executable(TaiXiuSim ${SOURCES})

# Trỏ đường dẫn đến thư mục include/ để ứng dụng biết chỗ tìm các file thiết kế giao diện (.h)
target_include_directories(TaiXiuSim PRIVATE include)
