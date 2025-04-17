start_server {tags {"del"}} {
    test {DEL IFEQ non-existing key} {
        r del foo
        assert_equal 0 [r del foo IFEQ "test"]
    }

    test {DEL IFEQ existing key, matching value} {
        r set foo "test"
        assert_equal 1 [r del foo IFEQ "test"]
    }

    test {DEL IFEQ existing key, non-matching value} {
        r set foo "nope"
        assert_equal 0 [r del foo IFEQ "test"]
    }
}
