#include <iostream>
#include <list>

class YouTubeChannel {
  public:
  // interface

    // YouTubeChannel constructor
    YouTubeChannel(std::string name_, std::string owner_name_) {
      name = name_;
      owner_name = owner_name_;
      subscriber_count = 0;
      likes = 0;
    }

    void get_info() {
      // print attributes to console
      std::cout << "Name: " << name << '\n';
      std::cout << "Owner name: " << owner_name << '\n';
      std::cout << "Subscriber count: " << subscriber_count << '\n';
      std::cout << "Likes: " << likes << '\n';
      std::cout << "Videos:\n";
      for(std::string video: published_video_titles) {
        std::cout << " - " << video << '\n';
      }
    }

    void subscribe() {
      // increment subscriber_count
      ++subscriber_count;
    }

    void unsubscribe() {
      // decrements subscriber_count
      // pre-conditions: subscriber_count > 0
      if(subscriber_count > 0) { --subscriber_count; }
    }

    void publish_video(const std::string& title) {
      published_video_titles.push_back(title);
    }

    void like(){
      ++likes;
    }

    // setters
    void set_name(const std::string& new_name) {
      name = new_name;
    }

    void set_owner(const std::string& new_owner) {
      owner_name = new_owner;
    }

    void set_about(const std::string new_about) {
      about = new_about;
    }

    // getters
    void get_name() {
      std::cout << name << '\n';
    }

    void get_owner() {
      std::cout << owner_name << '\n';
    }

    void get_about() {
      std::cout << name << ": "<< about << '\n';
    }

    void check_analytics() {
      if(likes<5) {
        std::cout << "This channel has low rated content\n";
      } else {
        std::cout << "This channel has high rated content\n";
      }
    }

  private:
  // implementation details
    // encapsulation: These properties should be updated using a methods via
    // the class' public interface
    std::string name;
    std::string owner_name;
    std::string about;
    std::list<std::string> published_video_titles;
    int subscriber_count;
    int likes;

  protected:
    // members here are accessible to all derived classes
};

// here CookingYouTubeChannel (a derived class) inherits everything from
// YouTubeChannel (the base class)
class CookingYouTubeChannel:public YouTubeChannel {
  public:                                                            // inherit the constructor from base
    CookingYouTubeChannel(std::string name_, std::string owner_name_):YouTubeChannel(name_, owner_name_) {
      // ...
    }
};

// here CookingYouTubeChannel (a derived class) inherits everything from
// YouTubeChannel (the base class)
class SingingYouTubeChannel:public YouTubeChannel {
  public:                                                            // inherit the constructor from base
    SingingYouTubeChannel(std::string name_, std::string owner_name_):YouTubeChannel(name_, owner_name_) {
      // ...
    }
};

int main() {
  std::cout << "[Learning Channel]\n";

  // test create new YouTube channel
  YouTubeChannel yt_channel("CodeBeauty", "Saldina");

  // publish videos
  yt_channel.publish_video("C++ for beginners");
  yt_channel.publish_video("HTML & CSS Video 1");
  yt_channel.publish_video("C++ OOP Video 1");

  // test subscribe/unsubsribe
  yt_channel.subscribe();
  yt_channel.subscribe();
  yt_channel.subscribe();
  yt_channel.unsubscribe(); // subscribers should be 2 after this call

  // view object state
  yt_channel.get_info();

  // change name and owner
  // yt_channel.set_name("CodingBeauty++");
  // yt_channel.set_owner("Saldina Nuvak");

  // view object's new state
  // yt_channel.get_info();

  // view channel name
  // yt_channel.get_name();

  // view channel owner
  // yt_channel.get_owner();

  std::cout << "\n[Cooking Channel]\n";

  // new cooking channel
  CookingYouTubeChannel cyt_channel("Amy's Kitchen", "Amy");
  cyt_channel.set_about("Practicing cooking, learning new recipes, experimenting with spices, ...");
  cyt_channel.publish_video("Apple Pie");
  cyt_channel.publish_video("Chocolate cake");

  cyt_channel.like();
  cyt_channel.like();
  cyt_channel.like();
  cyt_channel.like();
  cyt_channel.like();
  cyt_channel.like();

  cyt_channel.subscribe();
  cyt_channel.subscribe();

  cyt_channel.get_info();
  cyt_channel.get_about(); // ideally this should be inherited from the base

  std::cout << "\n[Singing Channel]\n";
  // new singing channel
  CookingYouTubeChannel syt_channel("John Sings", "John");
  syt_channel.set_about("Taking singing classes, learning new songs, learning how to dance ...");
  syt_channel.publish_video("Esc Sequence - Cover");
  syt_channel.like();

  syt_channel.subscribe();
  syt_channel.subscribe();
  syt_channel.subscribe();

  syt_channel.get_info();
  syt_channel.get_about(); // ideally this should be inherited from the base


  YouTubeChannel * yt1 {&cyt_channel};
  YouTubeChannel * yt2 {&syt_channel};

  std::cout << "\n[Channel Analytics]\n";

  yt1->check_analytics();
  yt2->check_analytics();

  return 0;
}
