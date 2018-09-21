502. Mini Cassandra
https://www.lintcode.com/problem/mini-cassandra/

Cassandra is a NoSQL storage. The structure has two-level keys.

Level 1: raw_key. The same as hash_key or shard_key.
Level 2: column_key.
Level 3: column_value
raw_key is used to hash and can not support range query. let's simplify this to a string.
column_key is sorted and support range query. let's simplify this to integer.
column_value is a string. you can serialize any data into a string and store it in column value.

implement the following methods:

insert(raw_key, column_key, column_value)
query(raw_key, column_start, column_end) // return a list of entries
Example
insert("google", 1, "haha")
query("google", 0, 1)
>> [（1, "haha")]

/**
 * Definition of Column:
 * class Column {
 * public:
 *     int key;
 *     String value;
 *     Column(int key, string value) {
 *         this->key = key;
 *         this->value = value;
 *    }
 * }
 */


class MiniCassandra {
public:
    MiniCassandra() {
        // do intialization if necessary
        this->table.clear();
    }

    /*
     * @param raw_key: a string
     * @param column_key: An integer
     * @param column_value: a string
     * @return: nothing
     */
    void insert(string &raw_key, int column_key, string &column_value) {
        // write your code here
        this->table[raw_key][column_key] = column_value;
    }

    /*
     * @param raw_key: a string
     * @param column_start: An integer
     * @param column_end: An integer
     * @return: a list of Columns
     */
    vector<Column> query(string &raw_key, int column_start, int column_end) {
        // write your code here
        vector<Column> result;
        if (this->table.count(raw_key)) {
            const map<int, string> & candidates = this->table[raw_key];
            map<int, string>::const_iterator a = candidates.lower_bound(column_start);
            map<int, string>::const_iterator b = candidates.upper_bound(column_end);
            for (map<int, string>::const_iterator it = a; it != b; ++it) {
                result.push_back(Column(it->first, it->second));
            }
        }
        return result;
    }

private:
    unordered_map<string, map<int, string>> table;
};