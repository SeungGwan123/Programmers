-- 코드를 입력하세요
with seoul as(
    select rest_id, rest_name, food_type, favorites, address
    from rest_info
    where address like '서울%'
), score as(
    select r.rest_id rest_id , round(avg(review_score),2) review_score
    from rest_review r, seoul s
    where r.rest_id = s.rest_id
    group by rest_id
)
select s.rest_id REST_ID, s.rest_name REST_NAME, s.food_type FOOD_TYPE, s.favorites FAVORITES, s.address ADDRESS, r.review_score SCORE
from seoul s, score r
where s.rest_id = r.rest_id
order by SCORE desc, favorites desc