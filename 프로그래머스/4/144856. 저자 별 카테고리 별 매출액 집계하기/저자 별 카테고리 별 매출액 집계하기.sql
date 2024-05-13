-- 코드를 입력하세요
with total_book as(
    select book_id, sum(sales) sales
    from book_sales
    where date_format(sales_date,"%Y-%m") = '2022-01'
    group by book_id
),total_price as(
    select b.book_id, category, author_id, sum(price*sales) total, price, sales
    from book b, total_book s
    where b.book_id = s.book_id
    group by book_id
), author_book as(
    select category, author_id, sum(total) total
    from total_price
    group by author_id, category
)
select a.author_id AUTHOR_ID, AUTHOR_NAME, t.category CATEGORY, total TOTAL_SALES
from author a, author_book t
where a.author_id = t.author_id
order by author_id, category desc

#select * from total_book
#select * from author_book
#select * from total_price

/* 결과
AUTHORID AUTHORNAME CATEGORY TOTAL_SALES
1 홍길동 인문 561000
1 홍길동 경제 1107000
2 김영호 소설 450000
3 김수진 생활 817000
3 김수진 기술 1523000
*/