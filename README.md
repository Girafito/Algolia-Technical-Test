# Algolia Technical Test
## Build
- mkdir build && cd build
- cmake ..
- make

## Usage
`./log\_analyzer <TSV log file>`

The given log file is supposed to be in TSV format. There should be one line per query and each line must look like :
    `YYYY-MM-DD hh-mm-ss\t<LOG>`

If there is no given file or the file cannot be openned, the program should return 1, 0 otherwise.

## Queries
The program can answer to two types of queries:
- Count : return the number of queries performed during a specific time range
  Format : `GET /1/queries/count/<DATE_PREFIX>`

- Top : return the most popular queries performed during a specific time range
  Format : `GET /1/queries/popular/<DATE_PREFIX>?size=<SIZE>`

## Encountered Problems

The final version of the project is far from perfect, mostly because of the API I used. The API is multi
threaded and I can not control how the threads are managed. This was the source of a lot of issues and the only
way I found to make it work was to open and thus parse the file when the first query is received.

The next step of this project is to rewrite the REST part with another API.

## Dependencies

- Pistache (http://pistache.io/)

## Author
Thomas Goncalves
thomas.goncalves@epita.fr
