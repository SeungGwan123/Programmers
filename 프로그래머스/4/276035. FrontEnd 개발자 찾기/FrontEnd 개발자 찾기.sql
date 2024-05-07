-- 코드를 작성해주세요
with skill as(
    select sum(code) skillcode
    from skillcodes
    where category = 'Front End'
)
select ID, EMAIL, FIRST_NAME, LAST_NAME
from developers d, skill
where d.skill_code & skill.skillcode
order by id