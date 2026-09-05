# Write your MySQL query statement below
(
select u.name as results from users u join movierating mr 
On u.user_id = mr.user_id
group by u.user_id
order by count(*) DESC,u.name
limit 1
)
UNION ALL
(
select m.title as results from Movies m join movierating mr 
On m.movie_id = mr.movie_id
where mr.created_at  between '2020-02-01' AND '2020-02-29'
group by m.movie_id,m.title

order by AVG(mr.rating) DESC,m.title
limit 1
);
-- where movierating.created_at between '2020-02-01' AND '2020-02-29' )