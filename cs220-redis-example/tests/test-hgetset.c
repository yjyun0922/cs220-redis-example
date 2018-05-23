#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <hiredis.h>

int main(int argc, char **argv) {
    redisContext *c;
    redisReply *reply;
    const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    int port = (argc > 2) ? atoi(argv[2]) : 6379;

    struct timeval timeout = { 1, 500000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }

    /* PING server */
    reply = redisCommand(c,"PING");
    printf("PING: %s\n", reply->str);
    freeReplyObject(reply);

    /* Set a key in a hash */
    reply = redisCommand(c,"HSET %s %s %s", "myhash", "name", "Random J. Redisuser");
    printf("HSET: %s\n", reply->str);
    freeReplyObject(reply);

    /* Use HGETSET */
    reply = redisCommand(c,"EXAMPLE.HGETSET %s %s %s", "myhash", "name", "Alan T. Foobar");
    printf("HGETSET: %s\n", reply->str);
    freeReplyObject(reply);

    /* Use HGET on the key we just HGETSET'd */
    reply = redisCommand(c,"HGET %s %s", "myhash", "name");
    printf("HGET: %s\n", reply->str);
    freeReplyObject(reply);

    /* Disconnects and frees the context */
    redisFree(c);

    return 0;
}
