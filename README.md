# DỰ ÁN: MÔ PHỎNG CHIẾN THUẬT TÀI XỈU
**0. Khái niệm tài xỉu:**

Tài xỉu là một trò chơi dưới hình thức cá cược. Trong trò chơi, có 03 viên xúc xắc 06 mặt được đánh số chấm từ 1-6, nhà cái sẽ lấy tổng của 03 mặt xúc xắc xuất hiện để ra một con số cuối cùng cho người chơi.

Nhiệm vụ của người chơi đó là dự đoán con số đó là tài hay xỉu, xỉu là tổng 3 mặt xúc xắc từ 3-10, còn tài là 11-18, nếu đoán đúng, người chơi sẽ thắng và được nhận về số tiền thưởng.

Với cách chơi đơn giản dễ chơi dễ trúng thưởng, tài xỉu luôn thu hút nhiều lượt người chơi, đặc biệt với hình thức online.
Tài xỉu online thường tồn tại dưới dạng một trang web, một ứng dụng trò chơi điện tử. Chỉ với một chiếc smartphone hay một chiếc máy tính, người chơi đã có thể tham gia chơi và cá cược bất cứ lúc nào.

**1. Tóm tắt nhanh: Chúng ta đang làm cái gì?**

Dự án này không phải là làm một con game giao diện đẹp mắt để người dùng ngồi click chuột chơi. Chúng ta đang lập trình một Hệ thống giả lập tự động (Simulation). Hệ thống này sẽ cho các "Người chơi ảo" đấu với "Nhà cái ảo" hàng chục vạn ván liên tục với tốc độ ánh sáng. Thông qua việc xuất dữ liệu và vẽ biểu đồ, chúng ta sẽ chứng minh bằng khoa học để trả lời 2 câu hỏi của giảng viên:

Người chơi đánh sao để tối ưu chuỗi thắng liên tục?

Nhà cái làm gì để không bao giờ bị sập và luôn có lãi?

**2. Luật chơi trong dự án này ra sao?**

Luật chơi được làm đơn giản hóa để nhóm dễ code:

Game sử dụng 3 viên xúc xắc. Tổng điểm từ 3 đến 10 là Xỉu, từ 11 đến 18 là Tài.

Xác suất thắng của cửa Tài và cửa Xỉu luôn là 50/50 công bằng tuyệt đối.

Để sòng bạc có thể duy trì hoạt động kinh doanh, cứ mỗi khi người chơi thắng, nhà cái sẽ thu 5% tiền phí hoa hồng (thu phế). Ví dụ: Bạn cược 100k, nếu thắng bạn chỉ nhận được 95k tiền lãi.

**3. Đứng ở góc độ Người Chơi: Bài toán tìm kiếm chuỗi thắng**

Mục tiêu của người chơi là "ăn nhiều tay liên tục nhất có thể". Để làm được điều này, người chơi ảo của chúng ta không đánh bừa mà phải dùng chiến thuật quản lý vốn. Nhóm sẽ code và so sánh 3 chiến thuật kinh điển:

Chiến thuật Martingale (Gấp thếp khi thua): Thua ván này, ván sau cược tiền gấp đôi để gỡ. Nhìn qua thì có vẻ an toàn, nhưng đây là "mồ chôn" của con bạc. Chỉ cần đen một chút (thua 7-8 ván liên tiếp), số tiền cần cược để gỡ sẽ khổng lồ và người chơi sẽ phá sản ngay lập tức.

3.2 Hệ thống Fibonacci (Kiểm soát biến động bảo thủ): Fibonacci là một tiến trình âm mềm mỏng hơn, trong đó số tiền cược sau một lần thua được tăng lên theo chuỗi toán học Fibonacci (1, 1, 2, 3, 5, 8...). Do không nhân đôi, quỹ đạo vốn bị sụt giảm chậm hơn đáng kể trong các chuỗi thua kéo dài. Mặc dù kiểm soát rủi ro xuất sắc, Fibonacci vẫn mang tính phòng thủ và không giải quyết trực tiếp bài toán "tối đa hóa chuỗi thắng" mà đề bài yêu cầu.

Chiến thuật Paroli (Nhân đôi khi thắng - Lựa chọn tối ưu): Thua thì giữ nguyên mức cược nhỏ nhất, nhưng nếu thắng thì lấy cả vốn lẫn lãi cược tiếp để tạo ra một chuỗi thắng lớn. Cách này dùng chính tiền của nhà cái để đầu tư, và nếu lỡ có thua ở giữa chừng, người chơi cũng chỉ mất đúng 1 đồng vốn nhỏ nhoi ban đầu. Đây là câu trả lời của nhóm cho cách chơi tối ưu nhất.

**4. Đứng ở góc độ Nhà Cái: Bài toán sinh tồn**

Nhà cái không trông chờ vào việc xúc xắc ra số mấy, họ dựa vào toán học. Ngoài việc thu phế 5% để có lợi nhuận, vũ khí phòng thủ mạnh nhất của nhà cái là Giới hạn bàn cược (Max Bet / Min Bet). 

Tại sao phải có mức cược tối đa? Để chống lại việc người chơi dùng chiến thuật gấp đôi tiền (Martingale) vô hạn. Khi áp dụng giới hạn này, nhà cái sẽ kích hoạt một định lý toán học gọi là "Sự sụp đổ của con bạc" (Gambler's Ruin). Định lý này nói rằng: Một người chơi có số tiền có hạn, khi đánh liên tục với một nhà cái có số tiền gần như vô hạn, thì cuối cùng người chơi chắc chắn sẽ mất trắng.

**5. Tại sao dự án này lại phải dùng Lập trình Hướng đối tượng (OOP)?**

Để hệ thống chạy hàng triệu ván mà không bị lỗi hay rối code, nhóm phải chia game thành các "Thực thể" (Objects) giống hệt đời thực: Dice (Viên xúc xắc), Table (Bàn chơi), Player (Người chơi), House (Nhà cái). Chúng ta sẽ áp dụng các bộ khung code chuẩn gọi là Design Patterns (Mẫu thiết kế). Ví dụ: Nhờ dùng "Strategy Pattern" (Mẫu thiết kế chiến lược), phần mềm của chúng ta có thể dễ dàng thay đổi "não bộ" của người chơi từ đánh kiểu Martingale sang đánh kiểu Paroli chỉ bằng 1 dòng code mà không làm ảnh hưởng đến luật của bàn chơi.
