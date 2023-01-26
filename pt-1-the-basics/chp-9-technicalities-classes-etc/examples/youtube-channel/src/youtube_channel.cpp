#include <iostream>
#include <list>

class YouTubeChannel {
  public:
    // member attributes
    std::string name;
    std::string owner_name;
    int subscriber_count;
    std::list<std::string> published_video_titles;

    // YouTubeChannel class object constructor
    YouTubeChannel(std::string name_, std::string owner_name_) {
      name = name_;
      owner_name = owner_name_;
      subscriber_count = 0;
    }
};

int main() {
  // channel instance 1
  YouTubeChannel yt_channel("CodeBeauty", "Saldina");
  yt_channel.published_video_titles.push_back("C++ for beginners");
  yt_channel.published_video_titles.push_back("HTML & CSS Video 1");
  yt_channel.published_video_titles.push_back("C++ OOP Video 1");

  // print attributes to console
  std::cout << "Name: " << yt_channel.name << '\n';
  std::cout << "Owner name: " << yt_channel.owner_name << '\n';
  std::cout << "Subscriber count: " << yt_channel.subscriber_count << '\n';
  std::cout << "Videos:\n";
  for(std::string video: yt_channel.published_video_titles) {
    std::cout << " - " << video << '\n';
  }

  // channel instance 2
  YouTubeChannel yt_channel2("AmySings", "Amy");
  yt_channel.published_video_titles.push_back("Johnny B - Cover");
  yt_channel.published_video_titles.push_back("Lorelei - Cover");

  std::cout << "Name: " << yt_channel2.name << '\n';
  std::cout << "Owner name: " << yt_channel2.owner_name << '\n';
  std::cout << "Subscriber count: " << yt_channel2.subscriber_count << '\n';
  std::cout << "Videos:\n";
  for(std::string video: yt_channel2.published_video_titles) {
    std::cout << " - " << video << '\n';
  }

  return 0;
}
