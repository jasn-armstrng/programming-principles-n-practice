#include <iostream>
#include "../headers/youtube_channel.h"

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
  CookingYouTubeChannel cyt_channel("Amy's Kitchen", "Amy"); // new cooking channel
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
  CookingYouTubeChannel syt_channel("John Sings", "John"); // new singing channel
  syt_channel.set_about("Taking singing classes, learning new songs, learning how to dance ...");
  syt_channel.publish_video("Esc Sequence - Cover");
  syt_channel.like();

  syt_channel.subscribe();
  syt_channel.subscribe();
  syt_channel.subscribe();

  syt_channel.get_info();
  syt_channel.get_about(); // ideally this should be inherited from the base

  std::cout << "\n[Channel Analytics]\n";
  cyt_channel.check_analytics();
  syt_channel.check_analytics();

  return 0;
}
