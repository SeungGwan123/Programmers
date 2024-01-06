-- 코드를 입력하세요
SELECT b.BOOK_ID, a.AUTHOR_NAME, concat(b.PUBLISHED_DATE) 
from book as b, author as a
where b.author_id = a.author_id and b.category='경제'
order by PUBLISHED_DATE asc