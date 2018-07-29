/* 355. Design Twitter

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able 
to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

- postTweet(userId, tweetId): Compose a new tweet.
- getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news 
  feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most 
  recent to least recent.
- follow(followerId, followeeId): Follower follows a followee.
- unfollow(followerId, followeeId): Follower unfollows a followee.

Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);*/


/*这道题让我们设计个简单的推特，具有发布消息，获得新鲜事，添加关注和取消关注等功能。我们需要用两个哈希表来做，第一个是
建立用户和其所有好友之间的映射，另一个是建立用户和其所有消息之间的映射。由于获得新鲜事是需要按时间顺序排列的，那么我们
可以用一个整型变量count来模拟时间点，每发一个消息，count自增1，那么我们就知道count大的是最近发的。那么我们在建立用户
和其所有消息之间的映射时，还需要建立每个消息和其时间点count之间的映射。这道题的主要难点在于实现getNewsFeed()函数，
这个函数获取自己和好友的最近10条消息，我们的做法是用户也添加到自己的好友列表中，然后遍历该用户的所有好友，遍历每个好友
的所有消息，维护一个大小为10的哈希表，如果新遍历到的消息比哈希表中最早的消息要晚，那么将这个消息加入，然后删除掉最早的
那个消息，这样我们就可以找出最近10条消息了*/

class Twitter {
private:
    int count;
    unordered_map<int, set<int>> friends;
    unordered_map<int, map<int, int>> tweets;
    
public:
    /** Initialize your data structure here. */
    Twitter() {
        count = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert({count++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be 
    posted by users who the user followed or by the user herself. Tweets must be ordered from most recent 
    to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> recent10;
        set<int> friendSet = friends[userId];
        for (auto f : friendSet) {
            map<int, int> tweetMap = tweets[f];
            for (auto t : tweetMap) {
                recent10.insert({t.first, t.second});
                if (recent10.size() > 10) {
                    recent10.erase(recent10.begin());
                }
            }
        }
        for (auto it = recent10.rbegin(); it != recent10.rend(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            friends[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */






