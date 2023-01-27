#include <iostream>
#include <list>

class YouTubeChannel {
  public:
    // member attributes
    std::list<std::string> published_video_titles;

    // YouTubeChannel class object constructor
    YouTubeChannel(std::string name_, std::string owner_name_) {
      name = name_;
      owner_name = owner_name_;
      subscriber_count = 0;
    }

    void get_info() {
      // print attributes to console
      std::cout << "Name: " << name << '\n';
      std::cout << "Owner name: " << owner_name << '\n';
      std::cout << "Subscriber count: " << subscriber_count << '\n';
      std::cout << "Videos:\n";
      for(std::string video: published_video_titles) {
        std::cout << " - " << video << '\n';
      }
    }

  private:
    std::string name;
    std::string owner_name;
    int subscriber_count;
};

int main() {
  // channel instance 1
  YouTubeChannel yt_channel("CodeBeauty", "Saldina");
  yt_channel.published_video_titles.push_back("C++ for beginners");
  yt_channel.published_video_titles.push_back("HTML & CSS Video 1");
  yt_channel.published_video_titles.push_back("C++ OOP Video 1");

  yt_channel.get_info();

  // channel instance 2
  YouTubeChannel yt_channel2("AmySings", "Amy");
  yt_channel2.published_video_titles.push_back("Johnny B - Cover");
  yt_channel2.published_video_titles.push_back("Lorelei - Cover");

  yt_channel2.get_info();

  return 0;
}
