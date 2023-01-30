
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
