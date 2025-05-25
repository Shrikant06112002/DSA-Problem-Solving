# Write your MySQL query statement below
select activity_date as day,
    Count(distinct user_id ) as active_users
from Activity
where activity_date between '2019-06-28' and '2019-07-28'
group by day;

