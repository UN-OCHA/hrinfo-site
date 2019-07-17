<?php

/*
 * This file is part of the Predis package.
 *
 * (c) Daniele Alessandri <suppakilla@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Predis\Command;

/**
 * @group commands
 * @group realm-key
 */
class KeyExpireTest extends PredisCommandTestCase
{
    /**
     * {@inheritdoc}
     */
    protected function getExpectedCommand()
    {
        return 'Predis\Command\KeyExpire';
    }

    /**
     * {@inheritdoc}
     */
    protected function getExpectedId()
    {
        return 'EXPIRE';
    }

    /**
     * @group disconnected
     */
    public function testFilterArguments()
    {
        $arguments = array('key', 'ttl');
        $expected = array('key', 'ttl');

        $command = $this->getCommand();
        $command->setArguments($arguments);

        $this->assertSame($expected, $command->getArguments());
    }

    /**
     * @group disconnected
     */
    public function testParseResponse()
    {
        $command = $this->getCommand();

        $this->assertTrue($command->parseResponse(1));
        $this->assertFalse($command->parseResponse(0));
    }

    /**
     * @group connected
     */
    public function testReturnsFalseOnNonExistingKeys()
    {
        $redis = $this->getClient();

        $this->assertFalse($redis->expire('foo', 2));
    }

    /**
     * @medium
     * @group connected
     * @group slow
     */
    public function testCanExpireKeys()
    {
        $redis = $this->getClient();

        $this->assertEquals('OK', $redis->set('foo', 'bar'));

        $this->assertTrue($redis->expire('foo', 1));
        $this->assertSame(1, $redis->ttl('foo'));

        $this->sleep(2.0);
        $this->assertFalse($redis->exists('foo'));
    }

    /**
     * @group connected
     */
    public function testDeletesKeysOnNegativeTTL()
    {
        $redis = $this->getClient();

        $this->assertEquals('OK', $redis->set('foo', 'bar'));

        $this->assertTrue($redis->expire('foo', -10));
        $this->assertFalse($redis->exists('foo'));
    }
}
