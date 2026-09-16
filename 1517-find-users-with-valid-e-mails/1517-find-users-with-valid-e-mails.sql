# Write your MySQL query statement below
#the main convept here we are using Regular Expression That is all
# the game is going on
select user_id,name,mail from users
where mail REGEXP '^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\\.com$'
AND BINARY MAIL LIKE '%@leetcode.com';